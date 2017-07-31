#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int N, K = 0, i = 1;
		char x;
		scanf("%d", &N);
		while((scanf("%c", &x)) && x != '\n') K++;
		long r = N;
		while(i * K < N){
			r *= (N - (i * K));
			i++;
		}

		cout << r << endl;
	}
	return 0;
}