//Ordenamiento por conteo de datos entre 0 y 99
#include <iostream>
const int MAX = 100;
int veces[MAX];

using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n;i++){
		int x;
		cin>>x;
		x%=100;
		veces[x]++;
    }

    for(int i=0;i<MAX;i++){
		for(int j=0;j<veces[i]){
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}
