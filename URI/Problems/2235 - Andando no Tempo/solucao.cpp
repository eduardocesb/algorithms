#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int a, b, c;
	
	cin >> a >> b >> c;
	
	bool ok = (2 * max(a, max(b, c)) == a + b + c) || (a == b ) || (a == c) || (b == c);
	
	cout << (ok ? 'S' : 'N') << endl;
	
	return 0;
}
