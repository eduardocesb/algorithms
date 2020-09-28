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
#define MAXN 100020
#define MAXL 23
#define endl '\n'

using namespace std;

const ld PI = acos(-1.0);
const int BLOCK = 333;

set<pii> ans;
int vis[MAXN], tempo;

struct Grafo
{
    vi grafo[MAXN];

    void add(int u, int v)
    {
        grafo[u].PB(v);
    }

    void init(int N)
    {
        for(int i = 1; i <= N; i++)
            grafo[i].clear();
    }

    void dfs(int u = 1, bool ok = true)
    {
        vis[u] = tempo;
        for(auto v : grafo[u])
        {
            if(vis[v] == tempo) continue;

            ans.erase(ok ? pii(u, v) : pii(v, u));

            dfs(v, ok);
        }
    }
};

Grafo g1, g2;

int main(int argc, char const *argv[])
{
	optimize;
	
    int T, N, M, u, v;

    cin >> T;

    while(T--)
    {
        cin >> N >> M;

        g1.init(N);
        g2.init(N);

        ans.clear();

        int qtd = M - (2 * N);

        while(M--)
        {
            cin >> u >> v;

            ans.insert({u, v});

            g1.add(u, v);
            g2.add(v, u);
        }

        tempo++;
        g1.dfs(1, true);
        tempo++;
        g2.dfs(1, false);

        for(auto x : ans)
        {
            if(!qtd) break;
            qtd--;

            cout << x.first << " " << x.second << endl;
        }
    }

	return 0;
}