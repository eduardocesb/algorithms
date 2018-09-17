#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(int argc, char** argv)
{
	optimize;

	string n;

	cin >> n;

	int a = 0, b = 0;

	int tam = n.length();
	for(int i = 0; i < tam; i++)
		n[i] == '-' ? a++ : b++;
	if(!b)
		cout << "YES" << endl;
	else
		cout << (!(a % b) ? "YES" : "NO") << endl;
	return 0;
}
