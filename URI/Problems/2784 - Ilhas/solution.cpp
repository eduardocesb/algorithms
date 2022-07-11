//https://www.beecrowd.com.br/judge/pt/problems/view/2784
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

vii grafo[MAXN];

int N, M;

vector<int> Dijkstra(int origem)
{
    vector<int> dist(N, INF);
    vector<bool> vis(N, false);

    dist[origem] = 0;

    priority_queue<pii, vii, greater<pii>> pq;

    pq.push({dist[origem], origem});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (vis[u])
            continue;
        vis[u] = true;

        for (auto x : grafo[u])
        {
            int v = x.first;
            int c = x.second;

            if (dist[v] > dist[u] + c)
            {
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main(int argc, char **argv)
{
    optimize;

    cin >> N >> M;

    for (int i = 0, u, v, c; i < M; i++)
    {
        cin >> u >> v >> c;

        grafo[u - 1].EB(v - 1, c);
        grafo[v - 1].EB(u - 1, c);
    }

    int S;

    cin >> S;

    auto dist = Dijkstra(S - 1);

    int maior = -INF, menor = INF;

    for (int i = 0; i < N; i++)
        if (i != S - 1)
            maior = max(maior, dist[i]), menor = min(menor, dist[i]);

    cout << (maior - menor) << endl;

    return 0;
}