#include <iostream>
#include <vector>
#define INFINITO -1000000010
#define ll long long

using namespace std;

void merge_sort(vector<ll> &nums){
	int tam = nums.size();
	if(tam == 1)
		return;
	vector<ll> a, b;
	for (int i = 0; i < (tam + 1) / 2; ++i)
		a.push_back(nums[i]);
	for (int i = (tam + 1)/ 2; i < tam; ++i)
		b.push_back(nums[i]);
	merge_sort(a);
	merge_sort(b);
	a.push_back(INFINITO);
	b.push_back(INFINITO);
	int posicao_a = 0, posicao_b = 0;
	for (int i = 0; i < tam; ++i)
	{
		if(a[posicao_a] > b[posicao_b]){
			nums[i] = a[posicao_a];
			posicao_a++;
		}else{
			nums[i] = b[posicao_b];
			posicao_b++;
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	int N;
	ll x;
	cin >> N;
	vector<ll>nums;
	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		nums.push_back(x);
	}

	merge_sort(nums);

	for (int i = 0; i < N; ++i)
		cout << nums[i] << ' ';
	cout << endl;
	return 0;
}