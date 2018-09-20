#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int todec(string x)
{
	int r = 0;

	int tam = x.size(), i = 0;

	while(tam--)
		r += pow(2, i++) * (x[tam] - '0');
	return r;
}

int main(int argc, char** argv)
{
	optimize;
	string x;
	int N;

	while((cin >> N) && !cin.eof())
	{
		while(N-- && (cin >> x))
			cout << (char)todec(x);
		cout << endl;
	}

	return 0;
}
