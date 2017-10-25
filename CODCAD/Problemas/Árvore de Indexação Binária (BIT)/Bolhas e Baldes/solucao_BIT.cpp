/*
Solução utilizando a BIT...
*/
#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 100100

using namespace std;

class BIT{
private:
	int nums[MAXN];
	int N;

public:
	BIT(int N){
		this->N = N;
		memset(nums, 0, sizeof(nums));
	}

	void add(int posicao, int valor){
		for (; posicao > 0 ; posicao -= (posicao & -posicao))
			nums[posicao] += valor;
	}

	int get(int posicao){
		int r = 0;
		for (; posicao <= N; posicao += (posicao & -posicao))
			r += nums[posicao];

		return r;
	}
};

int main(int argc, char const *argv[])
{
	optimize;
	
	int N;

	while((cin >> N) && N){
		BIT nums(N);

		int r = 0, x;

		for (int i = 0; i < N; ++i){
			cin >> x;
			r += /*nums.get(N) - */nums.get(x);
			nums.add(x, 1);
		}

		cout << (r % 2 ? "Marcelo" : "Carlos") << endl;
	}	

	return 0;
}