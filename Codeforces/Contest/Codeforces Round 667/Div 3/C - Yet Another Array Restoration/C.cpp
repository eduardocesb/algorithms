//https://codeforces.com/contest/1409/problem/C
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
const ld PI = acos(-1.0);
const int BLOCK = 333;

int n, x, y;

bool ok (int razao)
{
    int k = n;
    for(int i = y; i >= x && k; i -= razao)
    {
        if(i < x) return false;
        if(i == x) return true;
        if(k == 0) return false;
        k--;
    }

    return false;
}

void test_case()
{
    cin >> n >> x >> y;

    // CASO TRIVIAL
    vi ans;

    for(int i = 1; i <= 100; i++)
    {
        if(ok(i))
        {
            for(int j = y; n && j > 0; j -= i)
            {
                ans.PB(j);
                n--;
            }

            for(int j = y + i; n; j += i)
            {
                ans.PB(j);
                n--;
            }

            break;
        }
    }

    for(auto &k : ans)
        cout << k << " ";
    cout << endl;
    
}

int main(int argc, char const *argv[])
{
	optimize;

    int T = 1;

    cin >> T;

    for(int t = 1; t <= T; t++)
    {
        test_case();
    }
	
	return 0;
}