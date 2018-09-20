#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int N, M;

	while(scanf("%d %d", &N, &M) == 2)
	{
		N *= M;
		int s = 0, x;
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &x);
			s += x;
		}
		printf("%d saca(s) e %d litro(s)\n", (s / 60), (s % 60));
	}

	return 0;
}
