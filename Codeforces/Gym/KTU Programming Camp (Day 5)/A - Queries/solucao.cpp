//https://codeforces.com/gym/100741/problem/A
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
#define MAXN 10010
#define MAXL 23
#define endl '\n'

using namespace std;

const ld PI = acos(-1.0);
const int BLOCK = 333;

ll bit[11][MAXN];
int N, M, Q;

void add(ll bit[], int p, int v)
{
    for(; p < MAXN; p += (p & -p))
        bit[p] += v;
}

ll sum(ll bit[], int p)
{
    ll ans = 0;

    for(; p; p -= (p & -p))
        ans += bit[p];

    return ans;
}

ll query(int l, int r, int m)
{
    return sum(bit[m], r) - sum(bit[m], l - 1);
}

ll nums[MAXN];

int main(int argc, char const *argv[])
{
	optimize;

    cin >> N >> M;
	
    for(int i = 1; i <= N; i++)
    {
        cin >> nums[i];

        add(bit[nums[i] % M], i, nums[i]);
    }

    cin >> Q;

    char op;
    int l, r, m;

    while(Q--)
    {
        cin >> op >> l >> r;

        if(op == 's')
        {
            cin >> m;

            cout << query(l, r, m) << endl;
        }
        else if(op == '+')
        {
            add(bit[nums[l] % M], l, -nums[l]);

            nums[l] += r;

            add(bit[nums[l] % M], l, nums[l]);

            cout << nums[l] << endl;
        }
        else
        {
            if(nums[l] >= r)
            {
                add(bit[nums[l] % M], l, -nums[l]);

                nums[l] -= r;

                add(bit[nums[l] % M], l, nums[l]);
            }
            
            cout << nums[l] << endl;
        }
    }

	return 0;
}