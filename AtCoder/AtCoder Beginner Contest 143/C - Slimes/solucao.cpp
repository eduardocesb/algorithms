//https://atcoder.jp/contests/abc143/tasks/abc143_c
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

	int N;
	string S;

	cin >> N >> S;

	int r = 0;

	char ult = '&';

	for(int i = 0; i < N; i++)
		if(S[i] != ult) r++, ult = S[i];

	cout << r << endl;

	return 0;	
} 	