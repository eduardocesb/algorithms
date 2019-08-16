#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 10010

using namespace std;

int nums[MAXN];

int main(int argc, char** argv)
{
	optimize;

	int N;

	while((cin >> N) && !cin.eof())
	{
		int sum = 0;

		for(int i = 0; i < N; i++)
		{
			cin >> nums[i];
			sum += nums[i];
		}


		if(sum % N)
			cout << -1 << endl;
		else
		{
			int media = sum / N, diff = 0;

			for(int i = 0; i < N; i++)
				diff += max(0, nums[i] - media);
			
			cout << diff + 1 << endl;
		}

	}

	return 0;
}
