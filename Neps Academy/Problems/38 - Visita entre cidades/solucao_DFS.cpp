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
#define MAXN 2000020
#define MAXL 23
#define endl '\n'

using namespace std;

const ld PI = acos(-1.0);
const int BLOCK = 333;

vector<pii> grafo[MAXN];

int N, A, B, pai[MAXN], peso[MAXN];

void dfs(int u, int p)
{
    for(auto x : grafo[u])
    {
        int v = x.first;
        int c = x.second;

        if(p != v)
        {
            pai[v] = u;
            peso[v] = c;
            dfs(v, u);
        }
    }
}

int main(int argc, char const *argv[])
{
	optimize;

    cin >> N >> A >> B;

    int u, v, c;

    for(int i = 1; i < N; i++)
    {
        cin >> u >> v >> c;

        grafo[u].EB(v, c);
        grafo[v].EB(u, c);
    }

    dfs(A, 0);

    int ans = 0;

    while(B != A)
    {
        ans += peso[B];
        B = pai[B];
    }


    cout << ans << endl;
	
	return 0;
}