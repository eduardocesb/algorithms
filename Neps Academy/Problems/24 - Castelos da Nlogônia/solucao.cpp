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
const ld PI = 2.0 * acos(0.0);
const int BLOCK = 333;

vi grafo[MAXN];
int pai[MAXN], nivel[MAXN], cor[MAXN];

namespace seg {
	ll seg[4*MAXN], lazy[4*MAXN];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = -1;
		if (l == r) return seg[p] = 0;
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (lazy[p] == -1) return;
		int m = (l+r)/2;
		seg[2*p] = lazy[p]*(m-l+1);
		seg[2*p+1] = lazy[p]*(r-(m+1)+1);
		lazy[2*p] = lazy[p], lazy[2*p+1] = lazy[p];
		lazy[p] = -1;
	}

	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		prop(p, l, r);
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}

	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return seg[p];
		if (a <= l and r <= b) {
			seg[p] = (ll)x*(r-l+1);
			lazy[p] = x;
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};

namespace hld {
	vector<int> g[MAXN];
	int pos[MAXN], sz[MAXN];
	int peso[MAXN], pai[MAXN];
	int h[MAXN], v[MAXN], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = peso[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i != p) {
			pai[i] = k;
			h[i] = (i == g[k][0] ? h[k] : i);
			build_hld(i, k, f); sz[k] += sz[i];

			if (sz[i] > sz[g[k][0]] or g[k][0] == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}

	void build(int root = 0) {
		t = 0;
		build_hld(root);
		seg::build(t, v);
	}

	ll query_path(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b], pos[a]);
		return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
	}
	void update_path(int a, int b, int x) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return (void)seg::update(pos[b], pos[a], x);
		seg::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
	}
	ll query_subtree(int a) {
		return seg::query(pos[a], pos[a]+sz[a]-1);
	}
	void update_subtree(int a, int x) {
		seg::update(pos[a], pos[a]+sz[a]-1, x);
	}
	int lca(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);
		return h[a] == h[b] ? b : lca(pai[h[a]], b);
	}
}

int main(int argc, char const *argv[])
{
	optimize;
	
	int N, M, u, v, c;

	cin >> N >> M;

	for(int i = 0; i < MAXN; i++) hld::peso[i] = hld::v[i] = 0;

	for(int i = 1; i < N; i++)
	{
		cin >> u >> v;

		hld::g[u - 1].PB(v - 1);
		hld::g[v - 1].PB(u - 1);
	}

	hld::build();

	while(M--)
	{
		cin >> u >> v >> c;

		hld::update_path(u - 1, v - 1, c);
	}

	for(int i = 1; i <= N; i++)
		cout << hld::query_path(i - 1, i - 1) << " \n"[i == N];

	return 0;
}