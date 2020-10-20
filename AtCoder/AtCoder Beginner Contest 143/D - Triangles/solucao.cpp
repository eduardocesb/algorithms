//https://atcoder.jp/contests/abc143/tasks/abc143_d
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 1000000000
#define MAXN 3010
#define MAXL 22

using namespace std;

int bit[MAXN], N, nums[MAXN];

void add(int i)
{
	for(; i; i -= (i & -i))
		bit[i]++;
}

int query(int i)
{
	int r = 0;
	for(; i < MAXN; i += (i & -i))
		r += bit[i];
	return r;
}

int query(int A, int B)
{
	//Maiores que B - A
	int x = query(B - A);
	//menores que A + B
	int y = query(A + B - 1);

	int z = y - x;

	return max(0, z - 3);
}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> nums[i];

	sort(nums, nums + N);

	ll r = 0LL;

	for(int i = 0; i < N; i++)
	{
		for(int j = i + 1; j < N; j++)
		{
			int k = query(abs(nums[j] - nums[i]) + 1);
			r += k;
		}

		add(nums[i]);
	}

	// r /= 3;
	cout << r << endl;

	return 0;	
} 	