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
#define MAXN 1000020
#define MAXL 23
#define endl '\n'

using namespace std;

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = acos(-1.0);
const int BLOCK = 333;

int dp[MAXN];


bool solve(int falta)
{
    if(falta < 1) return !falta;
    if(dp[falta] != -1) return dp[falta];

    if(solve(falta - 7))
    {
        cout << 7; 
        return dp[falta] = true;
    }

    if(solve(falta - 4))
    {
        cout << 4;

        return dp[falta] = true;
    }

    return dp[falta] = false;
}

int main(int argc, char const *argv[])
{
	optimize;

    memset(dp, -1, sizeof dp);

    int N;

    cin >> N;
	
    if(!solve(N))
        cout << -1;
    cout << endl;

	return 0;
}