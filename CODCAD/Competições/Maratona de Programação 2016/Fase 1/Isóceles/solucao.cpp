#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, r = 0;

	cin >> N;

	int nums[N + 2], esquerda[N + 2], direita[N + 2];

	esquerda[0] = direita[N + 1] = 0;

	for(int i = 1; i <= N; i++)
		cin >> nums[i];

	for(int i = 1; i <= N; i++)
		esquerda[i] = min(esquerda[i - 1] + 1, nums[i]);

	for(int i = N; i; i--)
		direita[i] = min(direita[i + 1] + 1, nums[i]);

	for(int i = 1; i <= N; i++)
		r = max(r, min(esquerda[i], direita[i]));

	cout << r << endl;
	return 0;
}