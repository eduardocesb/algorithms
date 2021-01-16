#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2'000'000'000'020LL
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

struct Node
{
	ll a, b, sum;

	Node *l ,*r;

	Node(ll a = 0, ll b = 0, ll sum = 0) : a(a), b(b), sum(sum), l(NULL), r(NULL) {}

	void add(ll pos, ll v)
	{
		if(a == b) return (void)(sum += v);

		ll mid = (a + b) / 2;

		if(pos <= mid)
		{
			if(!l) l = new Node(a, mid);

			l->add(pos, v);
		}
		else
		{
			if(!r) r = new Node(mid + 1, b);

			r->add(pos, v);
		}

		sum = (l ? l->sum : 0) + (r ? r->sum : 0); 
	}

	ll query(ll i, ll j)
	{
		if(j < a || i > b) return 0;

		if(i <= a && b <= j) return sum;

		return (l ? l->query(i, j) : 0) + (r ? r->query(i, j) : 0);
	}
};

int main(int argc, char const *argv[])
{
	optimize;
	
	int N;

	ll x, y;

	Node seg(0, INF);

	ll ans = 0;

	cin >> N;

	while(N--)
	{
		cin >> x >> y;

		ll pos = (x * x) + (y * y);

		ans += seg.query(0, pos);

		seg.add(pos, 1);
	}

	cout << ans << endl;


	return 0;
}