#include <bits/stdc++.h>

using namespace std;

int fat[6];

void _fat(){

	fat[0] = 1;

	for (int i = 1; i < 6; ++i)
		fat[i] = fat[i - 1] * i;
}

int main(int argc, char const *argv[])
{
	int n;

	_fat();

	while(scanf("%d", &n) && n){
		int r = 0;

		int j = 1;

		while(n)
			r += (n % 10) * fat[j++], n /= 10;	

		printf("%d\n", r);
	}

	return 0;
}