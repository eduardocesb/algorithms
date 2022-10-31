#include <bits/stdc++.h>
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
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;

//Dinamic Programming
ll dp[MAXN];
bool ja_calculei[MAXN];

ll fib(int N)
{
    if(N == 0) return 0;
    if(N == 1) return 1;

    if(ja_calculei[N]) return dp[N];

    ll resposta = fib(N - 1) + fib(N - 2);

    ja_calculei[N] = true;
    dp[N] = resposta;

    return resposta;
}

int main(int argc, char** argv)
{
	optimize;

    int T, N;

    cin >> T;

    while (T--)
    {
        cin >> N;

        cout << "Fib(" << N << ") = " << fib(N) << endl;
    }

	return 0;
}