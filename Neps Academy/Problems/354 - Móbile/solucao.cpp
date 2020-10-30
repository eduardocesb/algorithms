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

int N;

vi grafo[MAXN];

bool ans = true;

int dfs(int u, int p = -1)
{
    int sz = 1, tam = -1;

    for(int v : grafo[u]) if(v != p)
    {
        int x = dfs(v, u);
        sz += x;

        if(tam == -1) tam = x;

        //Está desbalanceado
        if(tam != x)
            ans = false;
    }

    return sz;
}

int main(int argc, char const *argv[])
{
	optimize;

    cin >> N;

    for(int i = 1, u, v; i <= N; i++)
    {
        cin >> u >> v;

        grafo[u].PB(v);
        grafo[v].PB(u);
    }

    dfs(0);

    cout << (ans ? "bem" : "mal") << endl;

	return 0;
}