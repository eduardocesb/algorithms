//https://codeforces.com/contest/1409/problem/F
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
#define MAXN 202
#define MAXL 23
#define endl '\n'

using namespace std;

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = acos(-1.0);
const int BLOCK = 333;

int dp[MAXN][MAXN][MAXN], N, K;

string S, T;

int solve(int i, int falta, int sum)
{
    if(i == N) return 0;
    int &ans = dp[i][falta][sum];
    if(~ans) return ans;

    ans = solve(i + 1, falta, sum);


    //TRANSFORMAR O CARACTERE i EM T[0]
    if(S[i] == T[0])
        ans = max(ans, solve(i + 1, falta, sum + 1));
    else if(falta)
        ans = max(ans, solve(i + 1, falta - 1, sum + 1));

    //TRANSFORMAR O CARACTERE i EM T[1]
    if(S[i] == T[1])
        ans = max(ans, sum + solve(i + 1, falta, sum + (T[0] == T[1])));
    else if(falta)
        ans = max(ans, sum + solve(i + 1, falta - 1, sum + (T[0] == T[1])));

    return ans;
}

void test_case()
{
    memset(dp, -1, sizeof dp);

    cin >> N >> K >> S >> T;

    cout << solve(0, K, 0) << endl;
}

int main(int argc, char const *argv[])
{
	optimize;

    int T = 1;

    // cin >> T;

    for(int t = 1; t <= T; t++)
    {
        test_case();
    }
	
	return 0;
}