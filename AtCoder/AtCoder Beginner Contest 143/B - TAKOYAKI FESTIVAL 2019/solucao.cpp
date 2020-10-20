//https://atcoder.jp/contests/abc143/tasks/abc143_b
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 1000000000
#define MAXN 55
#define MAXL 22

using namespace std;

int nums[MAXN], sum[MAXN];

int query(int l, int r)
{
	return sum[r] - sum[l - 1];
}

int main(int argc, char const *argv[])
{
	optimize;

	int N;

	cin >> N;


	sum[0] = 0;

	for(int i = 1; i <= N; i++)
	{
		cin >> nums[i];
		sum[i] = sum[i - 1] + nums[i];
	}

	int r = 0;

	for(int i = 1; i <= N; i++)
		r += query(i + 1, N) * nums[i];

	cout << r << endl;

	return 0;	
} 	