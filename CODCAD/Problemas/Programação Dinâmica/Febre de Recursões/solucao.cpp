#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, k, m;
	cin >> n >> k >> m;
	long a[n + 1], f[k + 1];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> f[i];

	for (int i = n + 1; i <= k ; ++i)
	{
		f[i] = 0;
		for (int j = 1; j <= n; ++j)
			f[i] += (a[j] * f[i - j]) % m;
	}

	cout << (f[k] % m) << endl;
	return 0;
}