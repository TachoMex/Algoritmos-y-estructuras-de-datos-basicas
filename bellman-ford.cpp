#include <cstdio>
typedef struct arista{
	int a,b,d;
}arista;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	arista E[m+m];
	for(int i=0;i<m;i++)
	{
		int a, b, d;
		scanf("%d%d%d",&a,&b,&d);
		E[i].a=E[i+m].a=a;
		E[i].b=E[i+m].b=b;
		E[i].d=E[i+m].d=d;
	}
	int min[n];
	int aux[n];
	for(int i=1;i<=n;i++)
	{
		min[i]=aux[i]=1<<30;
	}
	int o=1,d=n;
	min[o]=aux[o]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m+m;j++)
		{
			arista e=E[j];
			int nuevo=min[e.a]+e.d;
			if(nuevo<aux[e.b])
				aux[e.b]=nuevo;
		}
		for(int j=1;j<=n;j++)
			min[j]=aux[j];
		printf("\n");
	}
	for(int i=1;i<=n;i+)
		printf("%d ",min[i]);
	return 0;
}