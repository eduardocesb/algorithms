#include <bits/stdc++.h>
#define MAXK 44

using namespace std;
int N, K;
int primos[MAXK];

int solve(int i = 0, int produto = 1){
	//Caso eu tenha terminado de gerar um conjunto novo...
	if(i == K)
		return N / produto;

	//Se eu puder colocar aquele numero primo na solucao...
	if(N / primos[i] >= abs(produto))
		return solve(i + 1, produto) + solve(i + 1, produto * primos[i] * -1);
	//Se nao nao uso o primo...
	return solve(i + 1, produto);
}

int main(int argc, char const *argv[])
{
	cin >> N >> K;

	for (int i = 0; i < K; ++i)
		cin >> primos[i];

	cout << solve() << endl;
	return 0;
}