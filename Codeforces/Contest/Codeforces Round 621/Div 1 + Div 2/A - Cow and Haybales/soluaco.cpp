//https://codeforces.com/contest/1307/problem/A
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 2000020

using namespace std;

int N, D, nums[MAXN];

int solve()
{
	int ans = nums[0];
	for(int i = 1; D >= 0 && i < N; i++)
	{
		if(D >= nums[i] * i)
		{
			ans += nums[i];
			D -= nums[i] * i;
		}
		else
		{
			ans += D / i;
			break;
		}
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	optimize;

	int T;

	cin >> T;

	while(T--)
	{
		cin >> N >> D;

		for(int i = 0; i < N; i++)
			cin >> nums[i];

		cout << solve() << endl;
	}
	
	return 0;
}