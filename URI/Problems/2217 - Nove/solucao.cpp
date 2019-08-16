#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define MAXN 100010


using namespace std;

int main(int argc, char** argv)
{
	optimize;

	int N, x;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> x;

		cout << (x & 1 ? 9 : 1) << endl;
	}


	return 0;
}
