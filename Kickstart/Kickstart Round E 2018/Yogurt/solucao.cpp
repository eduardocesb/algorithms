#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MN 5010

using namespace std;

int nums[MN];

int main()
{
	optimize;
	int T, N, K;

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> N >> K;
		for(int i = 0; i < N; i++) cin >> nums[i];

		sort(nums, nums + N);

		int dia = 0, qtd = 0, r = 0;

		for(int i = 0; i < N; i++)
		{
			if(nums[i] <= dia) continue;
			qtd++;
			r++;
			if(qtd == K) qtd = 0, dia++;
		}

		cout << "Case #" << t << ": " << r << endl;
	}

	return 0;
}
