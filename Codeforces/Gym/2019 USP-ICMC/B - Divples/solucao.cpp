#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

using namespace std;

int main(int argc, char** argv)
{
	optimize;

	ll A, B;

	cin >> A >> B;

	ll root = sqrt(A);

	vector<ll> r;

	for(int i = 1; i <= root; i++)
	{
		if(A % i) continue;

		if(!(i % B)) r.push_back(i);

		ll x = A / i;

		if((1LL * i * i) != A && !(x % B))
			r.push_back(x);
	}


	sort(r.begin(), r.end());

	for(int i = 0; i < (int)r.size(); i++)
		cout << r[i] << " ";
	cout << endl;

	return 0;
}
