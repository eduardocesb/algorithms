#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	int N, D;

	cin >> N >> D;

	int nums[2 * N];

	long long r = 0;

	for (int i = 0; i < N; nums[N + i] = nums[i++])
		cin >> nums[i];

	long long sum = 0, direita = 0;
	for (int i = 0; i < N; ++i)
	{

		while(direita < i + N && sum < D)
			sum += nums[direita++];

		if(sum == D) r++;
		sum -= nums[i];
	}

	cout << r << endl;
	return 0;
}