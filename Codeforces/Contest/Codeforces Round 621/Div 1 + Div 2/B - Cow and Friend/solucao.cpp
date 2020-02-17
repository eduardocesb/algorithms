//https://codeforces.com/contest/1307/problem/B
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 2000020

using namespace std;

int nums[MAXN], N, X;

int solve()
{
	int ans = 0;

	bool ok = false;

	int best = 0;

	for(int i = 0; i < N; i++)
	{
		ok += nums[i] == X;
		best = max(best, nums[i]);
	}

	if(ok) return 1;

	if(best > X) return 2;

	return (X + best - 1) / best; 
}

int main(int argc, char const *argv[])
{
	optimize;

	int T;

	cin >> T;

	while(T--)
	{
		cin >> N >> X;

		for(int i = 0; i < N; i++) cin >> nums[i];

		cout << solve() << endl;
	}
	
	return 0;
}