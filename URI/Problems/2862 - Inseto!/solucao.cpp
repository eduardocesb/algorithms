#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int N, x;
	scanf("%d", &N);

	while(N-- && scanf("%d", &x))
		printf("%s\n", (x > 8000 ? "Mais de 8000!" : "Inseto!"));
	return 0;
}
