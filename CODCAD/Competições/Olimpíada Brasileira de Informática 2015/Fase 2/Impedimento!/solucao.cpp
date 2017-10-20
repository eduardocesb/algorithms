#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;
	
	int R, L, D;

	cin >> L >> R >> D;

	cout << ((R > 50 && L < R && R > D) ? 'S' : 'N') << endl;
	return 0;
}