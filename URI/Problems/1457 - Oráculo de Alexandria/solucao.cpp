#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, N, K;
	char c;

	scanf("%d", &T);

	long long r;

	for(int t = 0; t < T; t++)
	{
		r = 1;
		K = 0;

		scanf(" %d", &N);

		while(scanf("%c", &c) && c != '\n')
			K++;

		for (int i = 0; i * K < N ; ++i)
			r *= (N - (i * K));

		printf("%Ld\n", r);
	}

	return 0;
}