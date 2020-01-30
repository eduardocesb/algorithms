#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 200020

using namespace std;

int arvore[6 * MAXN], lazy[6 * MAXN], sum[MAXN], abre[MAXN], fecha[MAXN];

struct Reta
{
	int Y1, Y2;

	Reta(int Y1 = 0, int Y2 = 0) : Y1(Y1), Y2(Y2) {}

	bool operator < (const Reta &a) const
	{
		return Y1 < a.Y1;
	}
};

vector<Reta> retas;
int N;

void update_lazy(int no)
{
	arvore[no] += lazy[no];

	int e = 2 * no;
	int d = e + 1;

	lazy[e] += lazy[no];
	lazy[d] += lazy[no];

	lazy[no] = 0;
}

void update(int no, int l, int r, int a, int b, int v)
{
	update_lazy(no);

	if(l > r || r < a || l > b) return;

	if(a <= l && r <= b)
	{
		lazy[no] += v;
		update_lazy(no);
		return;
	}

	int e = 2 * no;
	int d = e + 1;
	int m = (l + r) / 2;

	update(e, l, m, a, b, v);
	update(d, m + 1, r, a, b, v);

	arvore[no] = max(arvore[e], arvore[d]);
}

int query(int no, int l, int r, int a, int b)
{
	if(l > r || r < a || l > b) return -INF;

	update_lazy(no);

	if(a <= l && r <= b) return arvore[no];

	int e = 2 * no;
	int d = e + 1;
	int m = (l + r) / 2;

	return max(query(e, l, m, a, b), query(d, m + 1, r, a, b));
}

struct Evento
{
	int v, idx, l, r;

	Evento(int v = 0, int idx = 0, int l = 0, int r = 0) : v(v), idx(idx), l(l), r(r) {}

	bool operator < (const Evento &a) const
	{
		return idx != a.idx ? idx < a.idx : v > a.v;
	}
};

int solve()
{
	int ans = 0;

	vector<Evento> eventos;

	for(auto r : retas)
		eventos.push_back(Evento(1, r.Y1, r.Y1, r.Y2)), eventos.push_back(Evento(-1, r.Y2, r.Y1, r.Y2));

	sort(eventos.begin(), eventos.end());

	int cont = 0;

	for(int i = 0; i < (int)eventos.size();)
	{
		int cury = eventos[i].idx;

		while(i < eventos.size() && eventos[i].idx == cury && eventos[i].v == 1)
			cont += eventos[i++].v;

		// cout << cont << " " << query(1, 1, 2 * N, 1, 2 * N) << endl;

		ans = max(ans, cont + query(1, 1, 2 * N, 1, 2 * N));

		while(i < eventos.size() && eventos[i].idx == cury && eventos[i].v == -1)
		{
			update(1, 1, 2 * N, eventos[i].l, eventos[i].r, 1);
			cont += eventos[i++].v;
		}

	}

	return ans;
}

int main(int argc, char const *argv[])
{	
	optimize;

	cin >> N;

	int x, Y1, Y2, cont = 1;

	map<int, int> mapa;

	for(int i = 0; i < N; i++)
	{
		cin >> x >> Y2 >> x >> Y1;

		retas.push_back(Reta(Y1, Y2));

		mapa[Y1] = 0;
		mapa[Y2] = 0;
	}

	for(auto it = mapa.begin(); it != mapa.end(); it++)
		 it->second = cont++;
	
	for(int i = 0; i < (int)retas.size(); i++)
	{
		retas[i].Y1 = mapa[retas[i].Y1];
		retas[i].Y2 = mapa[retas[i].Y2];
	}

	// sort(retas.begin(), retas.end());

	cout << solve() << endl;

	return 0;
}