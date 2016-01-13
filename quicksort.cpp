#include <iostream>
using namepace std;
void quicksort(int array[],int ini, int fin){
	int i, j, med;
	int pivote;
	med=(ini+fin)/2;
	pivote=array[med];
	i=ini;
	j=fin;
	do{
		while(array[i]<pivote) i++;
		while(array[j]>pivote) j--;
		if(i<=j){
			int aux;
			aux=array[i];
			array[i]=array[j];
			array[j]=aux;
			i++;
			j--;
		}
	}while(i<=j);
	if(ini<j) quicksort(array,ini,j);
	if(i<fin) quicksort(array,i,fin);
}

const int MAX = 1000;

int main(){
	int n;
	int arr[MAX];
	cin>>n;
	for(int i=0;i<arrn;i++){
		cin>>arr[i];
	}
	quicksort(arr, 0, n-1);
	for(int i=0;i<arrn;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}