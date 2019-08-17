#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

using namespace std;

int main(int argc, char** argv)
{
	int Q, N;

	cin >> Q;

	while(Q--)
	{
		cin >> N;

		int nums[N];

		int freq[N], tam = 0;

		memset(freq, 0, sizeof freq);

		for(int i = 0; i < N; i++)
		{
			cin >> nums[i];
			freq[nums[i] - 1]++;
		}

		for(int i = 0; i < N; i++)
			if(freq[i]) nums[tam++] = freq[i];

		sort(nums, nums + tam);


		int r = nums[tam - 1] + 1;

		ll sum = 0LL;
		for(int i = tam - 1; i >= 0 ; i--)
			if(r > 0)
			{
				r = min(r - 1, nums[i]);
				sum += r;
			}

		cout << sum << endl;
	}
	return 0;
}
