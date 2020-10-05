#include <bits/stdc++.h>
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define PB push_back
#define EB emplace_back
#define MAXN 2000020

using namespace std;

int n, m;
vector <int> grafo [120];
int pai[120], cor [120];

void dfs (int u, int p){

    for (auto vizinho : grafo[u]){
        
        if (vizinho != p){
            pai[vizinho] = u;

            dfs(vizinho, u);
        }

    }
}

int main(int argc, char const *argv[]){

    for (int i = 0; i < 120; i++){
        cor[i] = 0;
    }

    cin >> n >> m;

    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    for (int i = 0; i < m; i++){

        for (int j = 0; j < 120; j++){
            pai[j] = -1;
        }
        int p, q, c;
        cin >> p >> q >> c;
        dfs (p, -1);
        cor[p] = c;
        while (q != p) {
            cor[q] = c;
            q = pai[q];
            cor[q] = c;
        }
    }

    for (int i = 1; i <= n; i++){
        cout << cor[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}