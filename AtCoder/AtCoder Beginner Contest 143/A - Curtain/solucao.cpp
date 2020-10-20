#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 1000000000
#define MAXN 200020
#define MAXL 22

using namespace std;


int main(int argc, char const *argv[])
{
	optimize;


	int A, B;

	cin >> A >> B;

	int r = max(0, A - (2 * B));

	cout << r << endl;


	return 0;	
} 	