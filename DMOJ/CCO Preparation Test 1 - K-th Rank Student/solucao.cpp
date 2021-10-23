/*
Link: https://dmoj.ca/problem/ccoprep1p3
*/
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
#define os_type pii
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

int pai[MAXN], N, K, nums[MAXN];

ordered_set o_set[MAXN];

int find(int x)
{
    return pai[x] == x ? x : pai[x] = find(pai[x]);
}

void join (int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v) return;

    if (o_set[u].size() > o_set[v].size()) swap(u, v);

    for (auto x : o_set[u])
        o_set[v].insert(x);

    pai[u] = v;
}

int query(int u, int k)
{
    u = find(u);

    if ((int)o_set[u].size() < k) return -1;

    return o_set[u].find_by_order(k - 1)->second;
}

int main(int argc, char** argv)
{
	optimize;

    for (int i = 1; i < MAXN; i++)
        pai[i] = i;

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> nums[i];

        o_set[i].insert(pii(nums[i], i));
    }

    int u, v, Q;

    while (K--)
    {
        cin >> u >> v;

        join (u, v);
    }

    cin >> Q;

    char op;

    while (Q--)
    {
        cin >> op >> u >> v;

        if (op == 'B')
            join(u, v);
        else
            cout << query(u, v) << endl;
    }

	return 0;
}
