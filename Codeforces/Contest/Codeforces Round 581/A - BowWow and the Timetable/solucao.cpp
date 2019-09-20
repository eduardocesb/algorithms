#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

int main(int argc, char** argv)
{
	optimize;

	string S;

	cin >> S;

	int tam = S.length();

	if(S[0] == '0')
	{
		cout << 0 << endl;
		return 0;
	}

	int r = ((tam + 1) / 2);

	bool ok = true;

	for(int i = 1; i < tam; i++)
		if(S[i] == '1') ok = false;

	r -= ok && (tam & 1);

	cout << r << endl;

	return 0;
}
