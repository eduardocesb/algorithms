//https://codeforces.com/contest/1157/problem/B
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

	int f[10];

	cin >> N;
	cin >> S;

	for(int i = 1; i < 10; i++) cin >> f[i];

	for(int i = 0; i < N; i++)
	{
		bool flag = false;

		if((S[i] - '0') >= f[S[i] - '0']) continue;

		while(i < N && (S[i] - '0') <= f[S[i] - '0'])
		{
			S[i] = '0' + f[S[i] - '0'];
			i++;
			flag = true;
		}

		break;
	}

	cout << S << endl;

	return 0;
}