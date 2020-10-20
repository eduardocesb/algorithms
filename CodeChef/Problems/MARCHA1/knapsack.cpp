//https://www.codechef.com/problems/MARCHA1
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000020
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 1010
#define MAXL 23
#define endl '\n'

using namespace std;

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = 2.0 * acos(0.0);
const int BLOCK = 333;

int nums[22], N, M, dp[22][MAXN], ok[22][MAXN], tempo;

int solve(int i, int falta)
{
	if(!falta) return true;
	if(i == N || falta < 0) return false;
	if(ok[i][falta] == tempo) return dp[i][falta];

	ok[i][falta] = tempo;

	return dp[i][falta] = max(solve(i + 1, falta), solve(i + 1, falta - nums[i]));
}

int main(int argc, char const *argv[])
{
	optimize;

	int T;

	cin >> T;

	while(T--)
	{
		cin >> N >> M;

		for(int i = 0; i < N; i++) cin >> nums[i];

		tempo++;

		cout << (solve(0, M) ? "Yes" : "No") << endl;
	}
	
	return 0;
}