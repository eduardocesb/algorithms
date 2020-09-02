//https://codeforces.com/contest/217/problem/A
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

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = acos(-1.0);
const int BLOCK = 333;

vii pontos;
vi grafo[MAXN];
bool vis[MAXN];

bool dfs(int u)
{
    if(vis[u]) return false;
    vis[u] = true;

    for(auto &v : grafo[u])
        dfs(v);

    return true;
}

bool ok(pii a, pii b)
{
    return a.first == b.first or a.second == b.second;
}

int main(int argc, char const *argv[])
{
	optimize;

    int N;

    cin >> N;

    pontos.resize(N);

    for(auto &x : pontos)
        cin >> x.first >> x.second;

    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++)
            if(ok(pontos[i], pontos[j]))
            {
                grafo[i].PB(j);
                grafo[j].PB(i);
            }
    
    int ans = 0;

    for(int i = 0; i < N; i++)
        ans += dfs(i);

    cout << (ans - 1) << endl;
	
	return 0;
}