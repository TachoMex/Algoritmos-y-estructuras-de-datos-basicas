#include <iostream>
#include <cstring>
using namespace std;


void generar_patron(int tabla[], char patron[], int tam){
	tabla[0] = -1;
	int k = -1; //lleva el sufijo mas grande que a la vez es prefijo de la cadena misma
	for(int i = 1; i <= tam; i++){
		while(k >= 0 && patron[k+1] != patron[i]){ //si la cuenta de k e i van igual entonces el sufijo
										 //y el prefijo van iguales. Si son distintas utiliza 
										 //La misma tabla del patron para encontrar el prefijo
			k = tabla[k];
		}
		if(patron[i] == patron[k+1]){
			k++;
		}
		tabla[i] = ++k;
	}
}

void buscar_cadena(int tabla[],char patron[],int tamp, char texto[], int tamt){
	int k = -1;
	for(int i = 0; i < tamt; i++){
		while(k >= 0 and patron[k+1] != texto[i]){	
			k = tabla[k]; //Utiliza la tabla del patron cuando las cadenas sean diferentes. 
		}
		if(texto[i] == patron[k+1]){
			k++; //Como las cadenas son iguales en la misma posicion se pasa al siguiente
		}
		if(k == tamp-1) {
			cout<<"Encontrada en el indice "<<i-k<<endl;
			k = patron[k-1]; //Reinicia los contadores. 
		}
	}
}

int main(){
	char texto[] = "THIS IS A TEST TEXT TO TEST THE TEST";
	char patron[] = "TEST";
	int tabla[100];
	
	int n = strlen(patron);
	int m = strlen(texto);

	generar_patron(tabla, patron, n); 

	cout<<"Mostrando patron..."<<endl;
	for(int i=1;i<=n;i++){
		cout<<i<<": "<<patron[i-1]<<" "<<tabla[i-1]<<endl;
	}
	cout<<endl;

	buscar_cadena(tabla,patron,n,texto,m);

	return 0;
}