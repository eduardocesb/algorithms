#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int N, x, r = 0;

	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &x);
		if(x != 1) r++;
	}

	printf("%d\n", r);
	return 0;
}
