#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000020
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
#define MAXN 500020
#define MAXL 23
#define endl '\n'

using namespace std;

// (1 + sqrt(5)) / 2
const ld GOLDEN_RATIO = 1.6180339887498949025257388711906969547271728515625;
const ld PI = 2.0 * acos(0.0);
const int BLOCK = 333;

bool DEBUG;

struct Node
{
	int sum;

	Node(int x = 0) : sum(x), l(NULL), r(NULL) {}

	Node *l, *r;
};

void build(Node *root, int a, int b)
{
	if(a == b) return;

	int mid = (a + b) / 2;

	root->l = new Node();
	root->r = new Node();

	build(root->l, a, mid);
	build(root->r, mid + 1, b);
}

void update(Node *prev, Node *curr, int a, int b, int pos, int v)
{
	if(a == b) return (void)(curr->sum += v + prev->sum);

	if(pos < a || pos > b) return;

	int mid = (a + b) / 2;

	if(pos <= mid)
	{
		curr->r = prev->r;

		if(curr->l == NULL) curr->l = new Node();

		update(prev->l, curr->l, a, mid, pos, v);
	}
	else
	{
		curr->l = prev->l;

		if(curr->r == NULL) curr->r = new Node();

		update(prev->r, curr->r, mid + 1, b, pos, v);
	}

	curr->sum = curr->l->sum + curr->r->sum;
}

int query(Node *u, Node *v, Node *lca, Node *pai, int a, int b, int K)
{
	if(a == b) return a;

	int esq = u->l->sum + v->l->sum - lca->l->sum - pai->l->sum;
	int mid = (a + b) / 2;

	return (K <= esq ? query(u->l, v->l, lca->l, pai->l, a, mid, K) : query(u->r, v->r, lca->r, pai->r, mid + 1, b, K - esq));
}

int cnt(Node *root, int a, int b, int i)
{
	if(i < a || b < i) return 0;
	if(a == b) return root->sum;

	int mid = (a + b) / 2;

	return cnt(root->l, a, mid, i) + cnt(root->r, mid + 1, b, i);
}

int N, Q, peso[MAXN], nivel[MAXN], pai[MAXN][MAXL];

Node version[MAXN];

vi grafo[MAXN];

void dfs(int u = 1, int p = 0)
{
	pai[u][0] = p;
	nivel[u] = nivel[p] + 1;

	if(u == 8) DEBUG = true;

	update(&version[p], &version[u], 1, MAXN, peso[u], 1);

	DEBUG = false;

	for(auto v : grafo[u]) if(v != p)
		dfs(v, u);
}

void precalc()
{
	memset(pai, -1, sizeof pai);

	dfs();

	for(int i = 1; i < MAXL; i++)
		for(int u = 1; u <= N; u++)
			if(pai[u][i - 1] != -1)
				pai[u][i] = pai[pai[u][i - 1]][i - 1];
}

int LCA(int u, int v)
{
	if(nivel[u] < nivel[v]) swap(u, v);

	for(int i = MAXL - 1; i >= 0; i--)
		if(pai[u][i] != -1 && nivel[pai[u][i]] >= nivel[v])
			u = pai[u][i];

	if(u == v) return u;

	for(int i = MAXL - 1; i >= 0; i--)
		if(pai[u][i] != -1 && pai[v][i] != -1 && pai[u][i] != pai[v][i])
		{
			u = pai[u][i];
			v = pai[v][i];
		}

	return pai[u][0];
}

int main(int argc, char const *argv[])
{
	optimize;
	
	cin >> N >> Q;

	build(&version[0], 1, MAXN);

	for(int i = 1; i <= N; i++) cin >> peso[i];

	int u, v, K; 

	for(int i = 1; i < N; i++)
	{
		cin >> u >> v;

		grafo[u].PB(v);
		grafo[v].PB(u);
	}

	precalc();

	for(int i = 0; i < Q; i++)
	{
		cin >> K >> u >> v;

		int lca = LCA(u, v);

		cout << query(&version[u], &version[v], &version[lca], &version[pai[lca][0]], 1, MAXN, K) << endl;
	}

	return 0;
}