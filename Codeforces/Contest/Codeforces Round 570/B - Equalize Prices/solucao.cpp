#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 110

using namespace std;

int nums[MAXN], N, K;

int solve()
{
	int menor, maior;

	for(int i = 0; i < N; i++)
	{
		if(!i) menor = maior = nums[i];
		menor = min(menor, nums[i]);
		maior = max(maior, nums[i]);
	}

	if(menor + (2 * K) < maior)
		return -1;
	return menor + K;
}

int main(int argc, char** argv)
{
	optimize;

	int Q;

	cin >> Q;

	while(Q--)
	{
		cin >> N >> K;

		for(int i = 0; i < N; i++)
			cin >> nums[i];

		cout << solve() << endl;
	}

	return 0;
}
