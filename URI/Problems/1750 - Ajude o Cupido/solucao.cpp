#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;

	cin >> N;

	int nums[N + 2];

	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	sort(nums, nums + N);
	nums[N] = nums[0];

	int sol = 0, r = 0;

	for (int i = 0; i < N; i += 2)
	{
		sol += min(abs(nums[i] - nums[i + 1]), 24 - abs(nums[i] - nums[i + 1]));
		r += min(abs(nums[i + 1] - nums[i + 2]), 24 - abs(nums[i + 1] - nums[i + 2]));
	}

	cout << min(r, sol) << endl;

	return 0;
}