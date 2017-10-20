#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, A = 0, B = 0, x;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> x;

		if(x == 1)
			A = !A;
		else
			B = !B, A = !A;
	}

	cout << A << endl;
	cout << B << endl;
	return 0;
}