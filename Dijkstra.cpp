#include <stdio.h>
#define MAX_VER 10000
#define MAX_ARI 1000000
struct s_nodo{
    int nodo; // nodo guardado
    int valor; // valor hasta el momento
    int origen;
};

s_nodo monti[MAX_VER+1]; // nodos del monticulo
int pmonti[MAX_VER+1];   // posicion de nodo en monticulo
int nmonti;              // numeor de elementos en el monticulo

void sube(int x){
    int padre = x/2;
    while(padre > 0 && monti[padre].valor > monti[x].valor ) {
        //Intercambiar x y padre
        s_nodo aux = monti[padre];
        monti[padre] = monti[x];
        monti[x] = aux;
        //actualiza posiciones
        pmonti[monti[padre].nodo] = padre;
        pmonti[monti[x].nodo] = x;
        //actualiza analisis
        x = padre;
        padre = x/2;
    }
}

void mete(int nodo, int valor,int origen) {
    // crea nodo
    nmonti++;
    monti[nmonti].nodo = nodo;
    monti[nmonti].valor = valor;
    monti[nmonti].origen = origen;
    pmonti[nodo] = nmonti;
    //sube nodo
    sube(nmonti);
}

void baja(int x) {
    //calcula el posicion del primer hijo
    int hijo = 2*x;
    //mientras tenga algun hijo
    while(hijo <= nmonti) {
        // si tien dos hijos
        if(hijo + 1 <= nmonti) {
            //si el segundo hijo es mejor que el anterior considera ese hijo
            if(monti[hijo].valor > monti[hijo+1].valor) {
                hijo = hijo+1;
            }
        }
        // si hijo es mejor que el actual
        if(monti[hijo].valor < monti[x].valor) {
            //intercambia
            s_nodo aux = monti[x];
            monti[x] = monti[hijo];
            monti[hijo] = aux;
            //actualiza posiciones
            pmonti[monti[x].nodo] = x;
            pmonti[monti[hijo].nodo] = hijo;
            //actualiza analaisis
            x = hijo;
            hijo = 2*x;
        }else {
            return;
        }
    }
}

s_nodo saca(){
    s_nodo res = monti[1];
    //cambia el ultimo con el primero
    monti[1] = monti[nmonti];
    nmonti--;
    pmonti[monti[1].nodo] = 1;
    pmonti[res.nodo] = -1; // -1 indica que no esta en monticulo
    baja(1);
    return res;
}

bool montiVacio() {
    return nmonti == 0;
}

bool enMonticulo(int x){
    return pmonti[x] != 0;
}

void decreceA(int nodo,int valor,int origen){
    int pos = pmonti[nodo];
    monti[pos].valor = valor;
    monti[pos].origen = origen;
    sube(pos);
}

int val(int nodo){
    int pos = pmonti[nodo];
    return monti[pos].valor;
}

struct arista{
    int sig;
    int nodo;
    int valor;
};
arista aristas[MAX_ARI + 1];//lista de aristas
int naris;//numero de aristas en la estructura
int lista[MAX_VER + 1];//inicio de aristas de nodos
void agregaArista(int a,int b,int v){
    naris++;
    aristas[naris].nodo = b;
    aristas[naris].valor = v;
    aristas[naris].sig = lista[a];
    lista[a] = naris;
}
int origenes[MAX_VER+1];
int resultado[MAX_VER+1];
int nNodos;
int nAristas; //este numero es del caso de entrada
void dijkstra(int s){ // s es el nodo de inicio
    for(int i=1;i<=nNodos;i++){
        resultado[i] = -1;
    }
    mete(s,0,s);
    while(!montiVacio()) {
        s_nodo act = saca();
        resultado[act.nodo] = act.valor;
        origenes[act.nodo] = act.origen;
        int arista = lista[act.nodo];
        while(arista != 0) {
            int nodo = aristas[arista].nodo;
            int valor = aristas[arista].valor;
            int costo = valor + act.valor;
            if(!enMonticulo(nodo)) {
                mete(nodo, costo,act.nodo);
            }else{
                if(val(nodo) > costo){
                    decreceA(nodo,costo,act.nodo);
                }
            }
            //siguiente arista
            arista = aristas[arista].sig;
        }
    }
}
int inicio;
void imprimeTrayecto(int x) {
    if(x != inicio){
        imprimeTrayecto(origenes[x]);
        printf("->%d",x);
    }else{
        printf("%d",x);
    }
}

int main()
{
    scanf("%d %d",&nNodos,&nAristas);
    for(int i = 0; i < nAristas; i++){
        int a,b,v;
        scanf("%d %d %d",&a,&b,&v);
        agregaArista(a,b,v);
    }
    scanf("%d",&inicio);
    dijkstra(inicio);
    for(int i=1;i<=nNodos;i++){
        printf("%d %d\n",i,resultado[i]);
        imprimeTrayecto(i);
        printf("\n");
    }
    return 0;
}

/*
Ejemplo de entrada:
8 16
1 5 9
1 8 8
1 2 5
2 8 4
2 3 12
2 4 15
3 7 11
3 4 3
4 7 9
5 8 5
5 6 4
5 7 20
6 3 1
6 7 13
8 3 7
8 6 6
1
*/
