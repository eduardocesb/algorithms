#include <bits/stdc++.h>
#define MAXN 1000100

using namespace std;

int N, M;
int nums[MAXN];

unordered_map<int, int> posicao;

int LIS(){
	vector<int> pilha;

	for (int i = 0; i < M; ++i)
	{
		vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), nums[i]);

		if(it == pilha.end())
			pilha.push_back(nums[i]);
		else
			*it = nums[i];
	}

	return pilha.size();
}

int main(int argc, char const *argv[])
{
	scanf("%d %d", &N, &M);

	int x;

	for (int i = 0; i < N; ++i)
		cin >> x, posicao[x] = i;

	for (int i = 0; i < M; ++i)
	{
		cin >> x;
		if(posicao.find(x) != posicao.end())
			nums[i] = posicao[x];
		else
			i--, M--;
	}

	cout << LIS() << endl;

	return 0;
}