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
#define MAXN 22
#define MAXL 23
#define endl '\n'

using namespace std;

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = 2.0 * acos(0.0);
const int BLOCK = 333;

const int LIM = (1 << 20) + 10;

int ok[LIM], dp[LIM], N, M, nums[22], tempo;

bool solve(int mask)
{
	int sum = 0;

	for(int j = 0; j < N; j++)
		if(mask & (1 << j))
			sum += nums[j];

	if(sum >= M) return (sum == M);

	if(ok[mask] == tempo) return dp[mask];

	ok[mask] = tempo;

	bool ans = false;

	for(int i = 0; i < N; i++)
		if(!(mask & (1 << i)))
			ans += solve(mask | (1 << i));

	return dp[mask] = ans;
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

		cout << (solve(0) ? "Yes" : "No") << endl;
	}
	return 0;
}

