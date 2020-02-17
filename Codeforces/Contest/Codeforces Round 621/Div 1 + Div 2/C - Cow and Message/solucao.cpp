//https://codeforces.com/contest/1307/problem/C
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 1000020

using namespace std;

string S;

int sum[27][MAXN];
int freq[30];

ll dp[30][30];

ll solve()
{
	int maior = 0;
	
	for(int i = 0; i < (int)S.length(); i++)
	{
		maior = max(maior, ++freq[S[i] - 'a']);
		for(int j = 0; j < 27; j++)
			sum[j][i + 1] = sum[j][i];

		sum[S[i] - 'a'][i + 1]++;
	}
	for(int i = 0; i < (int)S.length(); i++)
		for(int j = 0; j < 27; j++)
			dp[j][S[i] - 'a'] += sum[j][i];

	ll ans = 0LL;

	for(int i = 0; i < 27; i++)
		for(int j = 0; j < 27; j++)
			ans = max(ans, dp[i][j]);

	return max((ll)maior, ans);

}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> S;

	cout << solve() << endl;
	
	return 0;
}