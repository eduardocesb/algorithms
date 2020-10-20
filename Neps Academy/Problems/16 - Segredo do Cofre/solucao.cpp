//https://neps.academy/problem/16
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000020LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 200020
#define MAXL 23
#define endl '\n'

using namespace std;

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = 2.0 * acos(0.0);
const int BLOCK = 333;

int freq[MAXN][10], ans[10];

int sum(int l, int r, int x)
{
	return freq[r][x] - freq[l - 1][x];
}

int main(int argc, char const *argv[])
{
	optimize;

	int N, M, x, ant = 0;
	
	cin >> N >> M;

	for(int i = 1; i <= N; i++)
	{
		cin >> x;

		for(int j = 0; j < 10; j++)
			freq[i][j] = freq[i - 1][j];

		freq[i][x]++;
	}

	while(M--)
	{
		cin >> x;

		if(x > ant)
			for(int i = 0; i < 10; i++)
				ans[i] += sum(ant + 1, x, i);
		else
			
			for(int i = 0; i < 10; i++)
				ans[i] += sum(x, ant - 1, i);

		ant = x;
	}

	for(int i = 0; i < 10; i++)
		cout << ans[i] << " \n"[i == 9];

	return 0;
}