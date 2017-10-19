#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int A, B, C, D;

	cin >> A >> B >> C >> D;

	//Imprime a maior das duas áreas...
	cout << (max(A * B, C * D)) << endl;
	return 0;
}