#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int A, B, C, D;

	cin >> A >> B >> C >> D;

	cout << ((B == C && B + C == D && B + C + D == A) ? 'S' : 'N') << endl;
	return 0;
}