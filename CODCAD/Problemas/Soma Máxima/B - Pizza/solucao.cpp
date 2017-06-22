#include <iostream>

using namespace std;

int nums[200000];

int maximo(int inicio, int fim){
	int r = -1, maior = 0;
	for (int i = inicio; i < fim; ++i)
	{
		maior += nums[i];
		if (maior < 0)
		{
			maior = 0;
		}

		if(r < maior){
			r = maior;
		}
	}

	return r;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
		nums[n+i] = nums[i];
	}

	int max = 0;
	int r = 0;

	for (int i = 0; i < n; ++i)
	{
		max = maximo(i, n+i);
		if(r < max){
			r = max;
		}
	}

	cout << r << endl;

	return 0;
}