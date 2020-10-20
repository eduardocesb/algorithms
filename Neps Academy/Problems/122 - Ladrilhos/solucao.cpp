//https://neps.academy/problem/122
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
#define MAXN 202
#define MAXL 23
#define endl '\n'

using namespace std;

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = acos(-1.0);
const int BLOCK = 333;

bool vis[MAXN][MAXN];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int mapa[MAXN][MAXN], H, L;

int dfs(int i, int j)
{
	if(!i or !j or i > H or j > L or vis[i][j]) return 0;

	vis[i][j] = true;

	int ans = 1;

	for(int k = 0; k < 4; k++)
		if(mapa[i + dx[k]][j + dy[k]] == mapa[i][j])
			ans += dfs(i + dx[k], j + dy[k]);

	return ans;
}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> H >> L;

	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= L; j++)
			cin >> mapa[i][j];

	int ans = INF;

	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= L; j++)
			if(!vis[i][j])
				ans = min(ans, dfs(i, j));

	cout << ans << endl;
	
	return 0;
}