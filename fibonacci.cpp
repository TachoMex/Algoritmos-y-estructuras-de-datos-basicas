#include <iostream>
#include <cmath>

using namespace std;
const double r5 = sqrt(5.0);
const double a0 = (1+r5) * 0.5;
const double a1 = (1-r5) * 0.5;
const double c0 = 1.0/r5;
const double c1 = -c0;
double fib(int n){
    return c0*pow(a0,n) + c1*pow(a1,n);

}

int memoria[100][2][2];
int siguiente;
const int MOD = 10000;
const int I = -1;
int multiplica(int a, int b){
    if(a == I)
        return b;
    if(b == I)
        return a;
    int c = siguiente++;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                memoria[c][i][j] += memoria[a][i][k] * memoria[b][k][j];
            }
            memoria[c][i][j] %= MOD;
        }
    }
    return c;
}

int pot(int a, int b){
    if(b==0)
        return I;
    if(b==1)
        return a;
    int t = pot(a,b/2);
    t = multiplica(t,t);
    t = multiplica(t,pot(a,b%2));
    return t;
}

void print(int n){
    if(n==I){
        cout<<"1 0"<<endl;
        cout<<"0 1"<<endl;
    }else{
        cout<<memoria[n][0][0]<<" "<<memoria[n][0][1]<<endl;
        cout<<memoria[n][1][0]<<" "<<memoria[n][1][1]<<endl;
    }
}


int main()
{
    memoria[0][0][0] = 0;
    memoria[0][0][1] = 1;
    memoria[0][1][0] = 1;
    memoria[0][1][1] = 1;
    siguiente = 1;
    cin.sync_with_stdio(0);
    cin.tie(0);

    cout<<"*******Formula recurrencia*******"<<endl;

    for(int i=0;i<10;i++){
        cout<<i<<": "<<fib(i)<<endl;
    }

    cout<<"******Exponenciacion binaria de matrices********"<<endl;
    for(int i=0;i<10;i++){
        int x = pot(0,i);
        cout<<i<<": "<<memoria[x][0][1]<<endl;
    }

    return 0;
}
