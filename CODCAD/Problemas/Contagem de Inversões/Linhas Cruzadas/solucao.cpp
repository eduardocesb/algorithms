#include <iostream>
#include <vector>
#define INFINITO 60010

using namespace std;

int merge_sort(vector<int> &nums){
	int tam = nums.size();
	if(nums.size() == 1)
		return 0;

	vector<int> a, b;
	for (int i = 0; i < (tam + 1) / 2; ++i)
		a.push_back(nums[i]);
	for (int i = (tam + 1) / 2; i < tam; ++i)
		b.push_back(nums[i]);

	int inversoes = merge_sort(a);
	inversoes += merge_sort(b);
	a.push_back(INFINITO);
	b.push_back(INFINITO);
	int posicao_a = 0, posicao_b = 0;
	for (int i = 0; i < tam; ++i)
	{
		if(a[posicao_a] < b[posicao_b]){
			nums[i] = a[posicao_a];
			posicao_a++;
		}else{
			nums[i] = b[posicao_b];
			posicao_b++;
			inversoes += ((tam + 1) / 2) - posicao_a;
		}
	}

	return inversoes;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	cout << merge_sort(nums) << endl;

	return 0;
}