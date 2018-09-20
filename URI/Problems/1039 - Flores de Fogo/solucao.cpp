#include <bits/stdc++.h>

using namespace std;

double dist(int a, int b, int c, int d)
{
	return sqrt(pow(a - c, 2) + pow(b - d, 2));
}

int main(int argc, char** argv)
{
	int r1, r2, x1, x2, y1, y2;
	while(scanf("%d%d%d%d%d%d", &r1, &x1, &y1, &r2, &x2, &y2) == 6)
		printf("%s\n", (dist(x1, y1, x2, y2) + r2 <= r1 ? "RICO" : "MORTO"));

	return 0;
}
