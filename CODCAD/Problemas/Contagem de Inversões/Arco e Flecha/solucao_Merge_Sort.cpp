#include <iostream>
#include <vector>
#define INFINITO 0

using namespace std;

long long inversoes(vector<long long> &nums){
	long long tam = nums.size();
	long long qtd_inversoes = 0;
	if(tam == 1)
		return 0;

	vector<long long> a, b;
	for (long long i = 0; i < (tam + 1) / 2; ++i)
		a.push_back(nums[i]);
	for (int i = (tam + 1) / 2; i < tam; ++i)
		b.push_back(nums[i]);
	long long tam_a = (tam + 1) / 2;
	long long tam_b = tam - tam_a;
	qtd_inversoes += inversoes(a);
	qtd_inversoes += inversoes(b);
	long long posicao_a = 0, posicao_b = 0;
	a.push_back(INFINITO);
	b.push_back(INFINITO);

	for (long long i = 0; i < tam; ++i)
	{
		if(a[posicao_a] > b[posicao_b] || tam_b == posicao_b){
			nums[i] = a[posicao_a++];
		}else{
			nums[i] = b[posicao_b++];
			qtd_inversoes += tam_a - posicao_a;
		}
	}
	return qtd_inversoes;
}

int main(int argc, char const *argv[])
{
	long long N, X, Y;
	cin >> N;
	vector<long long> nums(N);
	for (long long i = 0; i < N; ++i)
	{
		cin >> X >> Y;
		nums[i] = (X * X) + (Y * Y);
	}

	cout << inversoes(nums) << endl;
	return 0;
}