#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int N;

	cin >> N;

	int nums[N];

	for(int i = 0; i < N; i++) cin >> nums[i];

	int r = 0;

	for(int i = N - 1; i > 1; i--)
		if(nums[i] && !nums[i - 1] && nums[i - 2])
		{
			r++;
			nums[i - 2] = 0;
		}

	cout << r << endl;

	return 0;
}
