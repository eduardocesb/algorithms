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
	int sum;

	Node *l, *r;

	Node(int x = 0) : sum(x), l(NULL), r(NULL) {}
};

Node version[MAXN];

void build(Node *root, int a, int b)
{
	if(a == b) return;

	int mid = (a + b) / 2;

	root->l = new Node();
	root->r = new Node();

	build(root->l, a, mid);
	build(root->r, mid + 1, b);
}

int N, nums[MAXN];

void update(Node *prev, Node *curr, int a, int b, int pos, int v)
{
	if(a == b) return (void) (curr->sum += v);

	if(pos < a || pos > b) return;

	int mid = (a + b) / 2;

	if(pos <= mid)
	{
		curr->r = prev->r;

		if(!curr->l) curr->l = new Node();

		update(prev->l, curr->l, a, mid, pos, v);
	}
	else
	{
		curr->l = prev->l;

		if(!curr->r) curr->r = new Node();

		update(prev->r, curr->r, mid + 1, b, pos, v);
	}

	curr->sum = curr->l->sum + curr->r->sum;
}

int query(Node *L, Node *R, int a, int b, int K)
{
	if(a == b) return a;

	int esq = R->l->sum - L->l->sum;
	int mid = (a + b) / 2;

	return (K <= esq ? query(L->l, R->l, a, mid, K) : query(L->r, R->r, mid + 1, b, K - esq));
}

int main(int argc, char const *argv[])
{
	optimize;

	int Q, l, r, K;
	
	cin >> N >> Q;

	build(&version[0], 1, N);

	vi a;

	for(int i = 1; i <= N; i++)
	{
		cin >> nums[i];

		a.PB(nums[i]);
	}

	sort(ALL(a));
	UNIQUE(a);

	for(int i = 1; i <= N; i++)
		nums[i] = 1 + POS(a, nums[i]);

	for(int i = 1; i <= N; i++)
		update(&version[i - 1], &version[i], 1, N, nums[i], 1);


	while(Q--)
	{
		cin >> l >> r >> K;

		cout << a[query(&version[l - 1], &version[r], 1, N, K) - 1] << endl;
	}


	return 0;
}