#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1'000'000'000'000'000'000
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define vi vector<ll>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 101010
#define MAXL 23
#define endl '\n'
#define int ll

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int N, M;

vii grafo[MAXN];


int32_t main()
{
    optimize;

    cin >> N >> M;

    for (int i = 0, u, v, c; i < M; i++)
    {
        cin >> u >> v >> c;

        grafo[u].EB(v, c);
        grafo[v].EB(u, c);
    }

    queue<ll> fila;

    fila.push(1);

    vi level(N + 1, INF);

    level[1] = 1;
    vector<bool> vis(N + 1, false);

    while (!fila.empty())
    {
        ll curr = fila.front();
        fila.pop();

        if (vis[curr]) continue;
        vis[curr] = true;

        for (auto x : grafo[curr])
        {
            ll v = x.first;
            ll c = x.second;

            if (level[v] > level[curr] + 1)
            {
                level[v] = level[curr] + 1;
                fila.push(v);
            }
        }
    }


    ll ans = 0;

    for (int u = 2; u <= N; u++)
    {
        ll menor_level = INF;
        ll menor_custo = INF; 

        for (auto x : grafo[u])
        {
            ll v = x.first;
            ll c = x.second;

            if (level[v] < menor_level)
            {
                menor_level = level[v];
                menor_custo = c * level[v];
            }
            else if (level[v] == menor_level && c * level[v] < menor_custo)
                menor_custo = c * level[v];
        }

        ans += menor_custo;
    }

    cout << ans << endl;    


    return 0;
}