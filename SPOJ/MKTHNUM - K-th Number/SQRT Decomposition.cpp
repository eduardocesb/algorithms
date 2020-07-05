#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000020
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
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

struct Query
{
	int l, r, k, i;

	Query(int l = 0, int r = 0, int k = 0, int i = 0) : l(l), r(r), k(k), i(i) {}

	bool operator < (const Query &a) const
	{
		return l / BLOCK != a.l / BLOCK ? l / BLOCK < a.l / BLOCK : r < a.r;
	}
};

vector<Query> queries;
vector<int> original, nums, comprimido;
int N, M, freq[MAXN], bloco[MAXN], qtd_bloco[MAXN], sqr;
pii ans[MAXN];


void add(int pos)
{
	freq[comprimido[pos]]++;
	qtd_bloco[comprimido[pos] / sqr]++;
}

void remove(int pos)
{
	freq[comprimido[pos]]--;
	qtd_bloco[comprimido[pos] / sqr]--;
}

pii Kth(int K)
{
	int qtd = 0;

	for(int i = 0; i < sqr; i++)
	{
		if(qtd + qtd_bloco[i] < K) qtd += qtd_bloco[i];
		//RESPOSTA TA NO BLOCO i
		else
		{
			int base = i * sqr;

			for(int j = 0; j < sqr; j++)
			{
				if(qtd + freq[base + j] < K) qtd += freq[base + j];
				else return pii(nums[base + j], freq[base + j]);
			}
		}
	}

	return pii(-1, -1);
}

void solve()
{
	int lMO = 0, rMO = -1;

	sort(ALL(queries));

	for(int i = 0; i < M; i++)
	{
		int L = queries[i].l;
		int R = queries[i].r;
		int K = queries[i].k;
		int I = queries[i].i;

		while(lMO < L) remove(lMO++);
		while(lMO > L) add(--lMO);
		while(rMO < R) add(++rMO);
		while(rMO > R) remove(rMO--);

		ans[I] = Kth(K);
	}
}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> N >> M;

	int x;

	REP(i, 1, N)
	{
		cin >> x;
		original.PB(x);
		nums.PB(x);
	}

	sort(ALL(nums));
	UNIQUE(nums);

	REP(i, 0, N - 1)
		comprimido.PB(lower_bound(ALL(nums), original[i]) - nums.begin());


	while(sqr * sqr <= nums.size()) sqr++;

	REP(i, 1, M)
	{
		int l, r, k;
		cin >> l >> r >> k;

		queries.EB(l - 1, r - 1, k, i);
	}

	solve();

	REP(i, 1, M)
		cout << ans[i].first << endl;


	return 0;
}