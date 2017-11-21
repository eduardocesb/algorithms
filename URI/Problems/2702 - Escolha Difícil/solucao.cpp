#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int A, B, C, D, E, F;

	cin >> A >> B >> C >> D >> E >> F;

	cout << (max(0, D - A) + max(0, E - B) + max(0, F - C)) << endl;

	return 0;
}