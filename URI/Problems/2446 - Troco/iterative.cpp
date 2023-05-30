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
#define MAXN 100010
#define MAX_MOEDAS 1010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int N, M;
vi moedas;

bool dp[MAXN][MAX_COINS];

bool solve(int N, int moeda)
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (i == 0) dp[i][j] = true;
            else if (j == 0) dp[i][j] = false;
            else
            {
                dp[i][j] = dp[i][j - 1];

                if (dp[i][j] == true) continue;

                if (i >= moedas[j - 1])
                {
                    int new_change = i - moedas[j - 1];

                    dp[i][j] = dp[new_change][j - 1];
                }
            }
        }
    }

    return dp[N][M];
}

int main(int argc, char** argv)
{
    optimize;

    cin >> N >> M;

    moedas.resize(M);

    for (int &x : moedas) cin >> x;

    cout << (solve(N, 0) ? "S" : "N") << endl;

    return 0;
}