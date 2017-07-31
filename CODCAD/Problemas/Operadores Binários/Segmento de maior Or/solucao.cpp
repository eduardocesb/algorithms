#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, x, r;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		r = max(r, max(x, r | x));
	}

	cout << r << endl;
	return 0;
}