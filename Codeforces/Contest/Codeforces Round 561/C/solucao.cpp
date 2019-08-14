#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define pii pair<int, int>
#define MAXN 200100

using namespace std;

vector<int> nums;

int busca(int x, int y, int i)
{
	auto r = upper_bound(nums.begin(), nums.begin() + i, y);
	auto l = lower_bound(nums.begin(), nums.begin() + i, x);

	// cout << *l << " " << *r << endl;
	return r - l;
}

int main(int argc, char** argv)
{
	optimize;

	int N;

	cin >> N;

	int x;

	for(int i = 0; i < N; i++)
	{
		cin >> x;
		nums.push_back(abs(x));
	}

	sort(nums.begin(), nums.end());

	long long r = 0LL;

	for(int i = 0; i < N; i++)
	{
		int k = (nums[i] + 1 ) / 2;
		x = busca(k, nums[i], i);
		r += x;

		// cout << i << " " << k << " " << nums[i] << " " << x << endl;
	}

	cout << r << endl;

	return 0;
}