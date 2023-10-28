#include <bits/stdc++.h> // 2xDijkstra O( (M + N*Log(N)) )
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;

const int INF = 1e9;
const int N = 10010;
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m, s, t, p, x;
int a, b, c, q;
int d1[N], d2[N];
bool seen[N];

vector<ii> g1[N], g2[N];

void go(int s, int t, int (&dist)[N], const vector<ii> g[N])
{
    for (int i = 1; i <= n; ++i)
        dist[i] = INF;

    priority_queue<ii, vector<ii>, greater<ii>> fila;
    fila.push({0, s});
    dist[s] = 0;

    while (!fila.empty())
    {
        int u = fila.top().s;
        int d = fila.top().f;
        fila.pop();

        if (dist[u] < d)
            continue;

        for (int i = 0; i < g[u].size(); ++i)
        {
            int xx = g[u][i].s;
            int dd = g[u][i].f;
            if (d + dd < dist[xx])
            {
                dist[xx] = d + dd;
                fila.push({d + dd, xx});
            }
        }
    }
}

int main()
{

    cin >> q;
    while (q--)
    {
        cin >> n >> m >> s >> t >> p;
        for (int i = 1; i <= n; ++i)
            g1[i].clear(), g2[i].clear();

        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b >> c;
            g1[a].pb(mp(c, b));
            g2[b].pb(mp(c, a));
        }

        go(s, t, d1, g1);
        go(t, s, d2, g2);
        int ans = -1;

        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < g1[i].size(); ++j)
            {
                int u = g1[i][j].s;
                if (d1[i] + g1[i][j].f + d2[u] <= p)
                    ans = max(ans, g1[i][j].f);
            }

        cout << ans << "\n";
    }
}