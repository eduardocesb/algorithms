#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int A, B, C, D;

	cin >> A >> B >> C >> D;

	if(A == C && B == D)
		cout << 0 << endl;
	else if(/*A != C && */B == D)
		cout << 1 << endl;
	else if(A != C/* && B != D*/)
		cout << 1 << endl;
	else
		cout << 2 << endl;
	return 0;
}