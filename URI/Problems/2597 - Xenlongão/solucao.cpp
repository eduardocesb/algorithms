#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int N, x;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> x;

		int r = x - (int)sqrt(x);
		cout << r << endl;
	}
	
	return 0;
}
