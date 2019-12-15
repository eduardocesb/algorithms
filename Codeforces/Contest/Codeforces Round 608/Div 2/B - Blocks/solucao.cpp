//https://codeforces.com/contest/1271/problem/B

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 2000000000
#define MAXN 200020

using namespace std;

char contrario(char x)
{
	return x == 'W' ? 'B' : 'W';
}

bool solve(string S, char x)
{
	vector<int> r;

	for(int i = (int)S.length() - 1; i; i--)
		if(S[i] != x)
		{
			r.push_back(i);
			S[i - 1] = contrario(S[i - 1]);
		}

	if(S[0] != x) return false;

	cout << (int)r.size() << endl;

	for(auto i : r)
		cout << i << " ";
	cout << endl;

	return true;
}

int main(int argc, char const *argv[])
{
	optimize;

	int N;

	string S;

	cin >> N >> S;

	if(solve(S, 'W'))
		return 0;

	if(solve(S, 'B'))
		return 0;

	cout << -1 << endl;

	return 0;
}