#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

using namespace std;

int main(int argc, char** argv)
{
	optimize;

	ll A, B, C;

	cin >> A >> B >> C;

	ll r = A / C;
	A %= C;
	r += B / C;
	B %= C;

	ll diff = 0;
	if(A + B >= C) r++, diff = min(C - A, C - B);


	cout << r << " " << diff << endl;

	return 0;
}
