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
#define MAXN 220
#define MAXL 23
#define endl '\n'

using namespace std;

const ld PI = acos(-1.0);
const int BLOCK = 333;

int N, M, mapa[MAXN][MAXN];
bool vis[MAXN][MAXN];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int i, int j)
{
    vis[i][j] = true;

    int sz = 1;

    for(int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];

        if(x < 1 or x > N or y < 1 or y > M or mapa[i][j] != mapa[x][y] or vis[x][y]) continue;

        sz += dfs(x, y);
    }

    return sz;
}

int main(int argc, char const *argv[])
{
	optimize;

    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> mapa[i][j];

    int ans = INF;
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(!vis[i][j])
                ans = min(ans, dfs(i, j));

    cout << ans << endl;

	return 0;
}