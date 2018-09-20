#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int N, a, b;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d %d", &a, &b);
		int r = (b * log10(a)) + 1;
		printf("%d\n", r);
	}

	return 0;
}
