//https://www.spoj.com/problems/PSEGTREE/
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

const ld PI = acos(-1.0);
const int BLOCK = 333;

struct Node
{
    ll sum;

    Node *l, *r;

    Node(ll s = 0) : sum(s), l(NULL), r(NULL) {}
};

void update(Node *prev, Node *curr, int l, int r, int pos, ll v)
{
    if(l == r) return (void)(curr->sum = prev->sum + v);

    int mid = (l + r) / 2;

    if(pos <= mid)
    {
        curr->l = new Node();
        curr->r = prev->r;

        update(prev->l, curr->l, l, mid, pos, v);
    }
    else
    {
        curr->l = prev->l;
        curr->r = new Node();

        update(prev->r, curr->r, mid + 1, r, pos, v);
    }

    curr->sum = curr->l->sum + curr->r->sum;
}

ll query(Node *root, int l, int r, int a, int b)
{
    if(b < l or a > r) return 0LL;

    if(a <= l && r <= b) return root->sum;

    int mid = (l + r) / 2;

    return query(root->l, l, mid, a, b) + query(root->r, mid + 1, r, a, b);
}

ll nums[MAXN];

void build(Node *root, int l, int r)
{
    if(l == r) return (void)(root->sum = nums[l]);

    int mid = (l + r) / 2;

    root->l = new Node();
    root->r = new Node();

    build(root->l, l, mid);
    build(root->r, mid + 1, r);

    root->sum = root->l->sum + root->r->sum;
}

Node version[MAXN];

int main(int argc, char const *argv[])
{
	optimize;
	
    int N, M, op, a, b, c, K = 0;

    cin >> N;

    for(int i = 1; i <= N; i++)
        cin >> nums[i];

    build(&version[0], 1, N);

    cin >> M;

    while(M--)
    {
        cin >> op >> a >> b >> c;

        if(op == 1)
            update(&version[a], &version[++K], 1, N, b, c);
        else 
            cout << query(&version[a], 1, N, b, c) << endl;
    }

	return 0;
}