#include <bits/stdc++.h>
#define INFINITO 10010

using namespace std;

int main(int argc, char const *argv[])
{
	int N, dist = INFINITO;

	cin >> N;

	int nums[N], esquerda[N], direita[N];

	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	for (int i = 0; i < N; ++i)
		if(!nums[i]) esquerda[i] = dist = 0;
		else esquerda[i] = ++dist;


	dist = INFINITO;
	for (int i = N - 1; i >= 0; --i)
		if(!nums[i]) direita[i] = dist = 0;
		else direita[i] = ++ dist;

	for (int i = 0; i < N; ++i){
		int r = min(esquerda[i], direita[i]);
		if(r > 9) r = 9;

		cout << r << ' ';
	}

	cout << endl;
	return 0;
}