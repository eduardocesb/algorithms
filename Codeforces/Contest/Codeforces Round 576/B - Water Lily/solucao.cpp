#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

using namespace std;

int main(int argc, char** argv)
{
	optimize;

	ll H, L;
	
	cin >> H >> L;
	
	double A = ((H * H) + (L * L)) / (2.0 * H);

	cout << fixed << setprecision(13) << (A - H) << endl;
	
	return 0;
}
