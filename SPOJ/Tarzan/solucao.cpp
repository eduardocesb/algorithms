#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

#define MAXN 1010

using namespace std;

int N,D;
vector<int> lista[MAXN];

void dfs(int X, int Y){

    int d1 = sqrt((pow(X,2)+pow(Y,2))); //calcula a posicao do ponto que estou verificando;

    for(int cont=0; cont<N;cont++){
        int d2 = sqrt((pow(lista[0][cont],2) + pow(lista[1][cont],2)));
        int dist=0;

        if(d1 < d2){
            dist = d2-d1;
        }else{
            dist = d1-d2;
        }

        if((dist<=D) && (lista[2][cont]== -1)){
            lista[2][cont] = 1 ;
            dfs(lista[0][cont], lista[1][cont]);
        }
    }
}


int main(){
    cin >> N >> D;
    int x=0,y=1,v=2;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        lista[x].push_back(a);
        lista[y].push_back(b);
        lista[v].push_back(-1);
    }
    int r = 0;

    for(int i=0;i<N;i++){
        if(lista[2][i] ==-1){
            lista[2][i] = 1;
            r++;
            dfs(lista[0][i], lista[1][i]);
        }
    }
    if(r == 1){
        cout << "S";
    }else{
        cout << "N";
    }
    //cout << sqrt(numero) ;
    return 0;
}
