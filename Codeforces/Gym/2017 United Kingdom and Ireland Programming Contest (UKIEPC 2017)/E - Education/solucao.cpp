#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000000
#define pii pair<int, int>
#define ll long long
#define MAXN 5050
#define MAXL 23

using namespace std;

vector<pii> nums(MAXN), departamentos(MAXN);
bool vis[MAXN];

int main(int argc, char const *argv[])
{
	optimize;

	int N, M;

	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		cin >> nums[i].first;
		nums[i].second = i;
	}

	for(int i = 0; i < M; i++) cin >> departamentos[i].first;
	for(int i = 0; i < M; i++) cin >> departamentos[i].second;

	sort(nums.begin(), nums.begin() + N);

	vector<int> resp(N);

	for(int i = N - 1; i >= 0; i--)
	{
		int best = INF;
		for(int j = 0; j < M; j++)
			if(!vis[j] && nums[i].first <= departamentos[j].first && best > departamentos[j].second)
			{
				best = departamentos[j].second;
				resp[nums[i].second] = j + 1;
			}

		if(best == INF)
		{
			cout << "impossible" << endl;
			return 0;
		}

		vis[resp[nums[i].second] - 1] = true;
	}
	
	for(int i = 0; i < N; i++)
		cout << resp[i] << " \n"[i == N - 1];

	return 0;
}