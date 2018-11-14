#include <bits/stdc++.h>
#define MAXN 200200

using namespace std;

int nums[MAXN];
int N, x, L, R;

int solve(int x)
{
	return min(nums[x] - L, R - nums[x]) - 1;
}

int main(int argc, char** argv)
{
	char op;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> op >> x;

		if(!i) nums[x] = L--, R++;
		else if(op == 'L') nums[x] = L--;
		else if(op == 'R') nums[x] = R++;
		else cout << solve(x) << endl;
	}

	return 0;
}
