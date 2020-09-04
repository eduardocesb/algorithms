//https://codeforces.com/contest/1409/problem/E
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

struct Node
{
    int sum;

    Node *l ,*r;

    Node(int s = 0) : sum(s), l(NULL), r(NULL) {}
};

Node *seg;

int N, K, dp[MAXN][2];
vi nums;

void update(Node *root, ll l, ll r, ll pos, int v)
{
    if(l == r) return (void)(root->sum += v);

    ll mid = (l + r) / 2;

    if(pos <= mid)
    {
        if(!root->l) root->l = new Node();

        update(root->l, l, mid, pos, v);
    }
    else
    {
        if(!root->r) root->r = new Node();

        update(root->r, mid + 1, r, pos, v);
    }
    
    root->sum = (root->l ? root->l->sum : 0) + (root->r ? root->r->sum : 0);
}

int query(Node *root, ll l, ll r, ll a, ll b)
{
    if(a > b or b < l or a > r or !root) return 0;

    if(a <= l && r <= b) return root->sum;

    ll mid = (l + r) / 2;

    return query(root->l, l, mid, a, b) + query(root->r, mid + 1, r, a, b);
}

int solve(int p, int falta)
{
    if(falta < 0 or p >= N) return 0;
    if(dp[p][falta] != -1) return dp[p][falta];

    int ans = solve(p + 1, falta);

    int fim = upper_bound(ALL(nums), nums[p] + K) - nums.begin();

    ans = max(ans, (fim - p) + solve(fim, falta - 1));

    return dp[p][falta] = ans;
}

void test_case()
{
    seg = new Node();

    cin >> N >> K;

    for(int i = 0; i < N; i++)
        dp[i][0] = dp[i][1] = -1;

    nums.clear();

    int x;

    for(int i = 0; i < N; i++)
    {
        cin >> x;

        nums.PB(x);
    }
    
    for(int i = 0; i < N; i++)
        cin >> x;

    sort(ALL(nums));

    cout << solve(0, 1) << endl;

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