//https://codeforces.com/contest/490/problem/C

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

bool ok[MAXN];

int main(int argc, char const *argv[])
{
	optimize;
	
    string S;

    ll A, B;

    cin >> S >> A >> B;

    int N = S.size();

    ll num = 0, base;

    for(int i = 0; i < N; i++)
    {
        num = ((num * 10) + (S[i] - '0')) % A;

        ok[i] = (num % A == 0);
    }

    // for(int i = 0; i < N; i++)
    //     cout << ok[i] << " \n"[i == N - 1];

    num = 0, base = 1;

    bool flag = false;

    for(int i = N - 1; i > 0; i--)
    {
        base = (base * 10) % B;
        num = ((base * (S[i] - '0')) + num) % B;

        if(S[i] == '0') continue;

        if(ok[i - 1] && (num % B == 0))
        {
            cout << "YES" << endl;

            for(int j = 0; j < i; j++)
                cout << S[j];
            cout << endl;
            for(int j = i; j < N; j++)
                cout << S[j];
            cout << endl;

            return 0;
        }
    }

    cout << "NO" << endl;

	return 0;
}