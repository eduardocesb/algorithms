#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, x, r = 0;
	cin >> N;

	for (int i = 0; i < N; r += x, ++i)
		cin >> x;

	cout << r - N << endl;

	return 0;
}