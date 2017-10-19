#include <bits/stdc++.h>
#define MAXN 10

using namespace std;

int fat(int N){
	return (N < 2 ? 1 : N * fat(N - 1));
}

int mat[MAXN][MAXN];

int main(int argc, char const *argv[])
{
	int N, x;

	cin >> N;

	int fat_n = fat(N);

	for(int i = 1; i < fat_n; i++)
		for (int j = 0; j < N; ++j){
			cin >> x;
			mat[j][x]++;
		}

	for (int j = 0; j < N; ++j)
		for (int i = 1; i <= N; ++i)
			if(mat[j][i] < mat[j][i + 1] || i == N){
				cout << i << ' ';
				break;
			}

	cout << endl;
	return 0;
}