#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, A, B, C, D, E, F, G;
	cin >> N >> A >> B >> C >> D >> E >> F >> G;
	cout << (N - G == A + B + C - D - F - E ? 'N' : 'S') << endl;
	return 0;
}