#include <cstdio>
#include <cstring>
int main()
{
	int G[100][100];
	memset(G,0,sizeof(G));
	int visitados[100];
	int min[100];
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		visitados[i]=0;
		min[i]=1<<30;
	}
	for(int i=0;i<m;i++)
	{
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		G[a][b]=G[b][a]=d;
	}
	int o=1,d=n;
	min[0]=1<<30;
	min[o]=0;
	for(int i=1;i<=n;i++)
	{
		int a=0;
		for(int j=1;j<=n;j++)
			if(!visitados[j] && visitados[j]<visitados[a])
				a=j;
				
		visitados[a]=1;
		for(int j=1;j<=n;j++)
			if(G[a][j]!=0 && min[j]>min[a]+G[a][j])
				min[j]=min[a]+G[a][j];
	}
	for(int i=1;i<=n;i++)
		printf("%d ",min[i]);
	return 0;
}