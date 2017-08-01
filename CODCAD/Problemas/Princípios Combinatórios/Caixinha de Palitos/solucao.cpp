#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	long long int r = 0;
	for (int i = 1; i <= M; ++i)
	{
		int resto = N - i;
		if(2 * M < resto) continue;
		int minimo = max(1, resto - M);
		int maximo = min(resto - 1, M);
		r += maximo - minimo + 1;
	}

	cout << r << endl;
	return 0;
}