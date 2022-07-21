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
#define MAXN 201010
#define MAXL 23
#define mid ((l + r) / 2)
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int N, M, seg_tree[4 * MAXN], nums[MAXN];

void build(int node, int l, int r, bool is_xor)
{
    if (l == r)
    {
        seg_tree[node] = nums[l];
        return;
    }

    build(2 * node, l, mid, !is_xor);
    build(2 * node + 1, mid + 1, r, !is_xor);

    if (is_xor)
        seg_tree[node] = (seg_tree[2 * node] ^ seg_tree[2 * node + 1]);
    else
        seg_tree[node] = (seg_tree[2 * node] | seg_tree[2 * node + 1]);

    //cerr << seg_tree[2 * node] << " " << (is_xor ? "xor" : "or") << " " << seg_tree[2 * node + 1] << " = " << seg_tree[node]  << endl;
}

int query(int node, int l, int r, int pos, int v, bool is_xor)
{
    if (pos < l || pos > r) return seg_tree[node];
    if (l == r) return seg_tree[node] = v;
    assert(l < r);
    
    if (is_xor)
        return seg_tree[node] = query(2 * node, l, mid, pos, v, !is_xor) ^ query(2 * node + 1, mid + 1, r, pos, v, !is_xor);
    else
        return seg_tree[node] = query(2 * node, l, mid, pos, v, !is_xor) | query(2 * node + 1, mid + 1, r, pos, v, !is_xor);
}

int main(int argc, char** argv)
{
    optimize;

    cin >> N >> M;

    bool is_xor = !(N & 1);

    N = 1 << N;

    for (int i = 1; i <= N; i++)
        cin >> nums[i];

    build(1, 1, N, is_xor);

    while (M--)
    {
        int pos, v;

        cin >> pos >> v;

        cout << query(1, 1, N, pos, v, is_xor) << endl;
    }

    return 0;
}