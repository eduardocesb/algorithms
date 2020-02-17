#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000000
#define pii pair<int, int>
#define ll long long
#define ld long double
#define MAXN 100100
#define MAXL 23

using namespace std;

int solve(string S)
{
	int ans = 0, sum = 0, ok = 0;

	for(int i = 0; i < (int)S.length(); i++)
	{
		if(S[i] == '1')
		{
			if(ok) ans += sum;
			ok = 1;
			sum = 0;
		}
		else sum++;
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	optimize;

	string S;
	int N;

	cin >> N;

	while(N--)
	{
		cin >> S;

		cout << solve(S) << endl;
	}

	
	return 0;
}