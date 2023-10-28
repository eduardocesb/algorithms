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
#define vi vector<ll>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

struct No
{
    ll sum, ans;
};

No arvore[MAXN * 4];
ll lazy[MAXN * 4];

vi nums;

void build(int no, int l, int r)
{
    if (l == r)
    {
        arvore[no].sum = nums[l - 1];
        arvore[no].ans = (1LL * nums[l - 1] * nums[l - 1]) % MOD;
        return;
    }

    int mid = (l + r) / 2;
    int e = 2 * no;
    int d = e + 1;

    build(e, l, mid);
    build(d, mid + 1, r);

    arvore[no].sum = (arvore[e].sum + arvore[d].sum) % MOD;
    arvore[no].ans = (arvore[e].ans + arvore[d].ans) % MOD;
}

void propaga(int no, int l, int r)
{
    if (!lazy[no]) return;

    ll sum = arvore[no].sum;

    //Sum all elements in the range [L, R]
    arvore[no].sum = ((((r - l + 1) * lazy[no]) % MOD) + arvore[no].sum) % MOD;

    arvore[no].ans = ((((2 * (lazy[no] * sum) % MOD) % MOD) + ((((lazy[no] * lazy[no]) % MOD) * (r - l + 1))) % MOD) + arvore[no].ans) % MOD;

    if (l != r)
    {
        int e = 2 * no;
        int d = e + 1;
        lazy[e] = (lazy[e] + lazy[no]) % MOD;
        lazy[d] = (lazy[d] + lazy[no]) % MOD;
    }

    lazy[no] = 0LL;
}


void update(int no, int l, int r, int a, int b, ll x)
{
    propaga(no, l, r);

    if (a > r || b < l || a > b || l > r) return;

    if (a <= l && r <= b)
    {
        lazy[no] = (lazy[no] + x) % MOD;
        propaga(no, l, r);
        return;
    }

    int mid = (l + r) / 2;
    int e = 2 * no;
    int d = e + 1;

    update(e, l, mid, a, b, x);
    update(d, mid + 1, r, a, b, x);

    arvore[no].sum = (arvore[e].sum + arvore[d].sum) % MOD;
    arvore[no].ans = (arvore[e].ans + arvore[d].ans) % MOD;
}


ll query(int no, int l, int r, int a, int b)
{
    propaga(no, l, r);
    if (a > r || b < l || a > b || l > r) return 0LL;
    if (a <= l && r <= b) return arvore[no].ans;

    int mid = (l + r) / 2;
    int e = 2 * no;
    int d = e + 1;

    return (query(e, l, mid, a, b) + query(d, mid + 1, r, a, b)) % MOD;
}

int main(int argc, char** argv)
{
    optimize;

    int N, Q;

    cin >> N >> Q;

    for (int i = 1, x; i <= N; i++)
    {
        cin >> x;
        nums.PB(x);
    }

    build(1, 1, N);

    char op;
    ll l, r, x;

    while (Q--)
    {
        cin >> op >> l >> r;

        if (op == 'u')
        {
            cin >> x;
            update(1, 1, N, l, r, x);
        }
        else
        {
            cout << (query(1, 1, N, l, r) + MOD) % MOD << endl;
        }
    }

    return 0;
}