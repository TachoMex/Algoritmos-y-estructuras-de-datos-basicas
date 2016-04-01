#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10100;
const int infty = 1<<30;

int treeMax[N];
int treeData[N];

void make_tree(int i, int j, int ptr){
	if(i == j){
		treeMax[ptr] = treeData[i];
		return;
	}
	int izq = ptr<<1, der = izq|1, med = (i+j)>>1;
	make_tree(i,med,izq);
	make_tree(med+1,j,der);
	treeMax[ptr] = max(treeMax[izq], treeMax[der]);
	//cout<<"{ "<<ptr<<":("<<i<<","<<j<<") =  "<<treeMax[ptr]<<"}"<<endl;
}

void update_tree(int i, int j, int ptr, int pos, int val){
	if(pos < i or pos > j){
		return;
	}
	if(pos == i and pos == j){
		treeMax[ptr] = treeData[i] = val;
		return;
	}
	int izq = ptr << 1, der = izq | 1, med = (i+j)>>1;
	update_tree(i,med,izq,pos,val);
	update_tree(med+1,j,der,pos,val);
	treeMax[ptr] = max(treeMax[izq], treeMax[der]);
}

int query_tree(int i, int j, int xi, int xf, int ptr){
	if(j < xi or i > xf){
		return -infty;
	}

	if(i>=xi  and j <= xf){
		//cout<<"::"<<i<<" "<<j<<"---"<<xi<<" "<<xf<<endl;
		return treeMax[ptr];
	}

	int izq = ptr << 1, der = izq | 1, med = (i+j)>>1;
	return max (
		query_tree(i,med,xi,xf,izq),
		query_tree(med+1,j,xi,xf,der)
	);
}



int main(){
	int n, q;
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>treeData[i];
	}
	make_tree(0,n-1,1);
	for(int i=0;i<q;i++){
		int a, b;
		cin>>a>>b;
		cout<<query_tree(0,n-1,a,b,1)<<'\n';		
	}
	return 0;
}

/*
10 5
-10 -20 -30 -40 -11 -22 -33 -44 -15 -5
0 5
1 2
8 9
0 9
4 6
*/