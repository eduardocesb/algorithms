#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int N, Q, x, t = 1;

	while(scanf("%d %d", &N, &Q) && (N || Q))
	{
		vector<int> nums;

		while(N-- && scanf("%d", &x))
			nums.push_back(x);

		sort(nums.begin(), nums.end());

		printf("CASE# %d:\n", t++);

		while(Q-- && scanf("%d", &x))
		{
			vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), x);

			if(it == nums.end() || *it != x)
				printf("%d not found\n", x);
			else
				printf("%d found at %d\n", x, (it - nums.begin() + 1));
		}
	}

	return 0;
}
