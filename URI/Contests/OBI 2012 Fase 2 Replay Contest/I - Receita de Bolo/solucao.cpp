#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int A, B, C;
	cin >> A >> B >> C;
	A /= 2;
	B /= 3;
	C /= 5;
	cout << (min(A, min(B, C))) << endl;
	return 0;
}