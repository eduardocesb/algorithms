/*
Solução utilizando Merge Sort
*/
#include <bits/stdc++.h>
#define INFINITO 100100

using namespace std;

int merge_sort(vector<int> &nums){

	int tam = nums.size();

	if(tam == 1) return 0;

	int r = 0;

	vector<int> a, b;
	for (int i = 0; i < tam / 2; ++i)
		a.push_back(nums[i]);

	for (int i = tam / 2; i < tam; ++i)
		b.push_back(nums[i]);

	r += merge_sort(a);
	r += merge_sort(b);

	a.push_back(INFINITO);
	b.push_back(INFINITO);

	int cont_a = 0, cont_b = 0;

	for (int i = 0; i < tam; ++i)
	{
		if(a[cont_a] < b[cont_b])
			nums[i] = a[cont_a++];
		else{
			nums[i] = b[cont_b++];
			r += a.size() - cont_a - 1;
		}
	}

	return r;
}

int main(int argc, char const *argv[])
{
	int N;
	while((cin >> N) && N){
		vector<int> nums(N);
		for (int i = 0; i < N; ++i)
			cin >> nums[i];

		cout << (merge_sort(nums) % 2 ? "Marcelo" : "Carlos") << endl;
	}
	return 0;
}