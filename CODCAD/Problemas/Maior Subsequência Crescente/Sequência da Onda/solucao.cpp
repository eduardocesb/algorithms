#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 100100

using namespace std;

int N;
int best[MAXN];
vector<int> nums(MAXN);

void lis(){
	vector<int> pilha;

	for (int i = 0; i < N; ++i)
	{
		vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), nums[i]);

		if(it == pilha.end()){
			pilha.push_back(nums[i]);
			best[i] = pilha.size();
		}else{
			*it = nums[i];
			best[i] = it - pilha.begin();
		}
	}
}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	lis();

	int r = 0;
	vector<int> pilha;

	for (int i = N - 1; i > -1; --i){

		vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), nums[i]);

		if(it == pilha.end()){
			pilha.push_back(nums[i]);

			//Tamanho da maior sequencia vindo da direita...
			int tam = pilha.size();

			//verfica se é melhor atualizar o 'r'
			r = max(r, min(best[i], tam));
		}else{
			*it = nums[i];

			//Tamanho da maior sequencia vindo da direita...
			int tam = it - pilha.begin();

			//verfica se é melhor atualizar o 'r'
			r = max(r, min(best[i], tam));
		}
	}

	cout << 2 * r - 1 << endl;
	return 0;
}