#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 1010101
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

ll dp[MAXN];

ll solve(int N)
{
    if (N <= 2) return 1;
    if (~dp[N]) return dp[N];

    if (N % 2)
        return dp[N] = ((2 * solve(N - 1)) - solve(N / 2)) % MOD;
    else
        return dp[N] = (2 * solve(N - 1)) % MOD;
}

int main(int argc, char** argv)
{
    optimize;

    memset(dp, -1, sizeof dp);

    int N;

    cin >> N;

    cout << (solve(N) + MOD) % MOD << endl;

    return 0;
}