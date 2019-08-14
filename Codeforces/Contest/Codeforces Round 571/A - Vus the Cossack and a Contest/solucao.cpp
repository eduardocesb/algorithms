#include <bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	int n, m, k;

	cin >> n >> m >> k;

	cout << (m < n || k < n ? "No" : "Yes") << endl;
	return 0;
}