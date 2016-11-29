#include <cstdio>
#include <vector>
#include <iostream>
#define MAXN 50050

using namespace std;
//---------------------
int n,m;
int componente[MAXN];
vector<int> lista[MAXN];
//---------------------

void dfs(int x){
    for(int i = 0;i < (int)lista[x].size();i++){
            int v = lista[x][i];
            if(componente[v] == -1){
                componente[v] = componente[x];
                dfs(v);
            }
    }
}

int main(){
    cin >> n >> m;
    for(int j=1;j<=n;j++){
        componente[j] = -1;
    }
    for(int j=1;j<=m;j++){
        int a,b;
        cin >> a >> b;
        lista[a].push_back(b);
        lista[b].push_back(a);
    }

    int qtd_familias = 0;

    for(int j=1;j<=n;j++){
        if(componente[j] == -1){
            qtd_familias ++;
            componente[j] = qtd_familias;
            dfs(j);
        }
    }
    cout << qtd_familias;

    return 0;
}
