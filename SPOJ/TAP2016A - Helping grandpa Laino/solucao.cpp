//https://www.spoj.com/problems/TAP2016A/

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 2000020

using namespace std;

string S;

char solve()
{
	for(auto x : S)
		if(x == 'i') return 'N';

	return 'S';
}


int main(int argc, char const *argv[])
{
	optimize;

	while(!cin.eof() && (cin >> S))
		cout << solve() << endl;

	return 0;
}