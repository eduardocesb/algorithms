#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int P, A, B;

	cin >> P >> A >> B;

	cout << !((A + B) % 2 == P) << endl;
	return 0;
}