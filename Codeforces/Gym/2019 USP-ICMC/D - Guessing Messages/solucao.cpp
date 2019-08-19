#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

int main(int argc, char** argv)
{
	optimize;

	string a, b;

	cin >> a >> b;

	int tama = a.length();
	int tamb = b.length(), pos = 0;

	for(int i = 0; i < tama; i++)
		if(pos < tamb && a[i] == b[pos]) pos++;

	cout << (pos == tamb ? "YES" : "NO") << endl;

	return 0;
}
