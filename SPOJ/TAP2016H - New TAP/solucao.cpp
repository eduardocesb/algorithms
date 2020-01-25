//https://www.spoj.com/problems/TAP2016H/

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 1010

using namespace std;

int N, K, ok[MAXN][MAXN], tempo;
ld dp[MAXN][MAXN];

ld solve(int X, int Y)
{
	if(X < 0 || Y < 0) return 0.0;
	if(ok[X][Y] == tempo) return dp[X][Y];

	ok[X][Y] = tempo;

	if(X + Y == 0) return dp[X][Y] = 1.0;

	int TOTAL = X + Y + 1;
	if(TOTAL < K) return 0.0;

	if(TOTAL == K)
		return dp[X][Y] = ((2.0 * X) / (TOTAL * (TOTAL - 1)));

	int COMB = TOTAL * (TOTAL - 1);

	ld I_GANHA =  (2.0 * Y / COMB) * solve(X, Y - 1); // I ganha do J

	ld X_GANHA = (1.0 * X * (X - 1) / COMB) * solve(X - 1, Y); 	// X ganha de outro X
	X_GANHA += ((2.0 * X * Y) / COMB) * solve(X, Y - 1); 		// X ganha o Y
	ld Y_GANHA = ((1.0 * Y * (Y - 1)) / COMB) * solve(X, Y - 1);// Y ganha do Y

	return dp[X][Y] = I_GANHA + X_GANHA + Y_GANHA;
}

int main(int argc, char const *argv[])
{
	optimize;

	int X;

	cout << setprecision(4) << fixed;

	while(!cin.eof() && (cin >> N >> X >> K))
	{
		tempo++;
		cout << solve(X - 1, N - X) << endl;
	}
	
	return 0;
}