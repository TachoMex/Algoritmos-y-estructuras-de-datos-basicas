#include <iostream>
using namespace std;
int N,M;
const int MAX = 1000;
char mapa[MAX][MAX];
bool visitados[MAX][MAX];
int distancia[MAX][MAX];

/*
	estructura de datos edd
	estado_ini dato de entrada
	agregar edd estado_ini
	mientras edd no vacia:
		estado = dato siguiente de edd
		para cada vecino de estado
			si no visitado vecino
			agregar vecino a edd
			marcar como visitado vecino

*/

int cola[MAX*MAX*2];
int inicialCola = 0;
int finalCola = 0;
void agregar(int x){
	cola[finalCola] = x;
	finalCola++;
}

int recuperar(){
	int resultado = cola[inicialCola];
	inicialCola++;
	return resultado;
}

bool vacia(){
	return inicialCola == finalCola;
}

void bus_amplitud(int xi, int yi){
	agregar(xi);
	agregar(yi);
	visitados[xi][yi]=true;
	distancia[xi][yi]=0;
	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};
	while(not vacia()){
		int x, y;
		//Saca datos de la cola. 
		x = recuperar();
		y = recuperar();
		for(int i=0; i<4; i++){
			int vx, vy;
			vx = x+dx[i];
			vy = y+dy[i];

			distancia[vx][vy]=distancia[x][y]+1;
			visitados[vx][vy]=true;
			agregar(vx);
			agregar(vy);
		}
	}
}


int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>mapa[i];
	}
	int x, y;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(mapa[i][j]=='#'){
				x = i;
				y = j;
			}
		}
	}

	bus_prof_iterativa(x,y);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<distancia[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;

}