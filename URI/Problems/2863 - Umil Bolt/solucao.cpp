#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int T;

	double x, r;

	while(scanf("%d", &T) == 1)
	{
		r = 13;
		for(int i = 0; i < T; i++)
		{
			scanf("%lf", &x);
			r = min(r, x);
		}
		printf("%.2lf\n", r);
	}

	return 0;
}
