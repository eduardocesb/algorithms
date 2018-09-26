#include <bits/stdc++.h>
#define ll int

using namespace std;

ll delta(ll a, ll b, ll c)
{
	return ((b * b) - (4 * a * c));
}

int main(int argc, char** argv)
{
	int N;
	ll a, b, c;

	cin >> N;

	cout << setprecision(2) << fixed;

	for(int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		double r = delta(a, b, c) / (4.0 * a);
		cout << abs(r) << endl;
	}


	return 0;
}
