//https://codeforces.com/contest/813/problem/E
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
#define MAXN 100020
#define MAXL 23
#define endl '\n'

using namespace std;

const ld PI = acos(-1.0);
const int BLOCK = 333;

struct Node
{
    int sum;

    Node *l, *r;

    Node(int s = 0) : sum(s), l(NULL), r(NULL) {}
};

void update(Node *prev, Node *curr, int l, int r, int p, int v)
{
    if(l == r) return (void) (curr->sum = prev->sum + v);

    int m = (l + r) / 2;

    if(p <= m)
    {
        curr->l = new Node();
        curr->r = prev->r;

        update(prev->l, curr->l, l, m, p, v);
    }
    else
    {
        curr->l = prev->l;
        curr->r = new Node();

        update(prev->r, curr->r, m + 1, r, p, v);
    }

    curr->sum = curr->l->sum + curr->r->sum;
}

int query(Node *root, int l, int r, int a, int b)
{
    if(b < l or a > r) return 0;

    if(a <= l && r <= b) return root->sum;

    int m = (l + r) / 2;

    return query(root->l, l, m, a, b) + query(root->r, m + 1, r, a, b);
}

void build(Node *root, int l, int r)
{
    if(l == r) return;

    int m = (l + r) / 2;

    root->l = new Node();
    root->r = new Node();

    build(root->l, l, m);
    build(root->r, m + 1, r);
}

Node version[2000000];

queue<int> nums[MAXN];
int f[MAXN], cnt = 1;

int main(int argc, char const *argv[])
{
	optimize;

    build(&version[0], 1, MAXN);   
	
    int N, Q, K;

    cin >> N >> K;

    for(int i = 1, x; i <= N; i++)
    {
        cin >> x;

        update(&version[cnt - 1], &version[cnt], 1, MAXN, i, 1);
        nums[x].push(i);
        cnt++;

        if(nums[x].size() > K)
        {
            update(&version[cnt - 1], &version[cnt], 1, MAXN, nums[x].front(), -1);
            cnt++;
            nums[x].pop();
        }

        f[i] = cnt - 1;
    }

    cin >> Q;

    int ans = 0, l, r;

    while(Q--)
    {
        cin >> l >> r;

        l = ((l + ans) % N) + 1;
        r = ((r + ans) % N) + 1;

        if(l > r) swap(l, r);

        ans = query(&version[f[r]], 1, MAXN, l, r);

        cout << ans << endl;
    }


	return 0;
}