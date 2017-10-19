#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int A, B, C, D;

	cin >> A >> B >> C >> D;

	//É a diferença entre o maior somado ao menor e os dois do meio...
	cout << abs(2 * (max(max(A, B), max(C, D)) + min(min(A, B), min(C, D))) - (A + B + C + D)) << endl;
	return 0;
}