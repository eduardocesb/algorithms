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
#define MAXP 10000010
#define MAXL 23
#define endl '\n'

using namespace std;

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = acos(-1.0);
const int BLOCK = 333;

int F[MAXP], sum[MAXP];

void crivo()
{
    bitset<MAXP> composto;

    for(int i = 2; i < MAXP; i++)
    {
        if(composto[i]) continue;

        for(int j = i; j < MAXP; j += i)
        {
            composto[j] = true;
            sum[i] += F[j];
        }
    }
}

int main(int argc, char const *argv[])
{
	optimize;

    int N, M, x, L, R;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> x;
        F[x]++;
    }

    crivo();

    for(int i = 1; i < MAXP; i++)
        sum[i] += sum[i - 1];

    cin >> M;

    while(M--)
    {
        cin >> L >> R;

        L = min(L, MAXP - 1);
        R = min(R, MAXP - 1);

        cout << (sum[R] - sum[L - 1]) << endl;
    }

	return 0;
}