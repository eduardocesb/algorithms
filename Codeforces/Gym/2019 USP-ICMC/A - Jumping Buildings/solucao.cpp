#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 100100
#define pii pair<int, int>

using namespace std;

int resp[MAXN], nums[MAXN];

int main(int argc, char** argv)
{
	optimize;

	int N;

	cin >> N;

	stack<pii> pilha;

	memset(resp, -1, sizeof resp);

	for(int i = 0; i < N; i++)
	{
		cin >> nums[i];
		while(!pilha.empty() && pilha.top().first < nums[i])
		{
			pii topo = pilha.top();
			pilha.pop();

			resp[topo.second] = min(topo.first, i - topo.second - 1);
		}

		pilha.push(pii(nums[i], i));
	}

	for(int i = 0; i < N; i++)
		cout << (resp[i] == -1 ? min(nums[i], N - i - 1) : resp[i]) << " ";

	cout << endl;

	return 0;
}
