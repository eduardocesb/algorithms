#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 200020
#define MAXL 23
#define endl '\n'

using namespace std;

const ld PI = acos(-1.0);
const int BLOCK = 333;

vii grafo[MAXN];
int d[MAXN], vis[MAXN], N, M;

void Dijkstra(int origem)
{
    for(int i = 1; i <= N; i++)
        d[i] = INF;

    priority_queue<pii, vector<pii>, greater<pii>> fila;

    fila.push({0, origem});
    d[origem] = 0;

    while(!fila.empty())
    {
        int atual = fila.top().second;
        fila.pop();

        if(vis[atual]) continue;

        vis[atual] = true;

        for(auto x : grafo[atual])
        {
            int prox = x.first;
            int custo = x.second;

            if(d[prox] > d[atual] + custo)
            {
                d[prox] = d[atual] + custo;
                fila.push({d[prox], prox});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
	optimize;

    cin >> N >> M;

    for(int i = 0, u, v, c; i < M; i++)
    {
        cin >> u >> v >> c;

        grafo[u].EB(v, c);
        grafo[v].EB(u, c);
    }

    int SERVIDOR;

    cin >> SERVIDOR;

    Dijkstra(SERVIDOR);

    int maior = -INF, menor = INF;

    for(int i = 1; i <= N; i++)
        if(i != SERVIDOR)
        {
            maior = max(maior, d[i]);
            menor = min(menor, d[i]);
        }
	
    cout << maior - menor << endl;

	return 0;
}