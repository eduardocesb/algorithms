#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define INF 1000000000
#define MAXN 100100
#define MAXL 22

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	int T, X, Y;

	cin >> T;


	while(T--)
	{
		cin >> X >> Y;

		if(X == 1)
			cout << (Y == 1 ? "YES" : "NO") << endl;
		else if(X < 4)
			cout << (Y < 4 ? "YES" : "NO") << endl;
		else
			cout << "YES" << endl;
	}
	
	return 0;
}
