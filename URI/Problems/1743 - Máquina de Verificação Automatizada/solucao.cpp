#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int A[5], x;

	bool ok = true;

	for (int i = 0; i < 5; ++i)
		cin >> A[i];

	for (int i = 0; i < 5; ++i)
	{
		cin >> x;
		if(x + A[i] != 1)
			ok = false;
	}

	cout << (ok ? 'Y' : 'N') << endl;
	
	return 0;
}