#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, r = 0;

	cin >> N;

	int nums[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];

		if(i < 2) continue;

		if(!nums[i] && !nums[i - 1] && nums[i - 2])
			r++;
	}

	cout << r << endl;
	return 0;
}