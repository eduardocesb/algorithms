//https://neps.academy/problem/108
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1'000'000'010LL
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

struct Cara
{
	ll B, F, D;

	Cara(ll b = 0LL, ll f = 0LL, ll d = 0LL) : B(b), F(f), D(d) {}

	bool operator < (const Cara &a) const
	{
		return B != a.B ? B < a.B : F > a.F;
	}
};

vector<Cara> caras;

struct Node
{
	ll sum;

	Node *l, *r;

	Node(ll v = 0LL) : sum(v), l(NULL), r(NULL){}
};

void update(Node *root, ll l, ll r, ll p, ll v)
{
	assert(l <= p && p <= r);

	if(l == r) return (void)(root->sum = max(root->sum, v));

	ll mid = (l + r) / 2;

	if(p <= mid)
	{
		if(!root->l) root->l = new Node();

		update(root->l, l, mid, p, v);
	}
	else
	{
		if(!root->r) root->r = new Node();

		update(root->r, mid + 1, r, p, v);
	}

	root->sum = max((root->l ? root->l->sum : 0LL), (root->r ? root->r->sum : 0LL));
}

ll query(Node *root, ll l, ll r, ll a, ll b)
{
	if(b < l || a > r || a > b || !root) return 0LL;

	if(a <= l && r <= b) return root->sum;

	ll mid = (l + r) / 2;

	return max(query(root->l, l, mid, a, b), query(root->r, mid + 1, r, a, b));
}

Node root;

int main(int argc, char const *argv[])
{
	optimize;

	int N;

	ll b, f, d;

	cin >> N;

	map<pii, ll> aux;

	for(int i = 1; i <= N; i++)
	{
		cin >> b >> f >> d;

		aux[pii(b, f)] +=d;
	}

	for(auto &x : aux)
		caras.EB(x.first.first, x.first.second, x.second);

	sort(ALL(caras));

	for(auto c : caras)
		update(&root, 1, INF, c.F, query(&root, 1, INF, 1, c.F - 1) + c.D);

	cout << root.sum << endl;

	return 0;
}