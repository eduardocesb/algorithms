#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

using namespace std;


int main(int argc, char const *argv[])
{
	int V, N;

	cin >> V >> N;

	ll placas = V * N;

	for(int i = 10; i <= 90; i += 10)
		cout << (((placas * i) + 99) / 100) << " \n"[i == 90];

	return 0;
}
