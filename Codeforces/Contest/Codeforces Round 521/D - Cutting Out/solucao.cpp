#include <bits/stdc++.h>
#define pii pair<int, int>
#define MAXN 200200

using namespace std;

int nums[MAXN], frequencia[MAXN];
vector<pii> dados;

bool comp(pii a, pii b)
{
	return a > b;
}

int main(int argc, char** argv)
{

	int N, K;

	cin >> N >> K;

	for(int i = 0; i < N; i++)
	{
		cin >> nums[i];
		frequencia[nums[i]]++;
	}

	for(int i = 0; i < MAXN; i++)
		dados.push_back(pii(frequencia[i], i));

	sort(dados.begin(), dados.end(), comp);

	vector<int> r;

	int best = 0, sum = 0, id;

	for(int i = 0; i < K; i++)
	{
		if(!i)
		{
			best = dados[i].first / K;
			continue;
		}
		
		if((dados[i].first / K) > best)
		{
			best = sum / K;
			id = i;
		}
	}

	for(int i = 0; i <= id; i++)
	{
		int tam = dados[i].first / best;
		cout << " -- " << best << " " << tam << " " << dados[i].first << " -- " << endl;
		// for(int j = 0; j < tam; j++)
		// 	  cout << dados[i].second << " ";
	}

	// cout << endl;

	return 0;
}
