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

int N, M, nums[MAXN], no_bloco[MAXN];
vi a;

struct Query
{
    int L, R, i;

    Query(int l = 0, int r = 0, int i = 0) : L(l), R(r), i(i) {}

    bool operator < (const Query &a) const
    {
        return (no_bloco[L] != no_bloco[a.L]) ? (L < a.L) : (R < a.R);
    }
};

vector<Query> queries;

int F[MAXN], ans[MAXN], curr;

void add(int p)
{
    int v = a[nums[p]];

    if(F[nums[p]] == v) curr--;

    F[nums[p]]++;

    if(F[nums[p]] == v) curr++;
}

void remove(int p)
{
    int v = a[nums[p]];

    if(F[nums[p]] == v) curr--;

    F[nums[p]]--;

    if(F[nums[p]] == v) curr++;
}

int main(int argc, char const *argv[])
{
	optimize;
	
    cin >> N >> M;

    for(int i = 0; i < MAXN; i++)
        no_bloco[i] = i / BLOCK;

    for(int i = 0; i < N; i++)
    {
        cin >> nums[i];

        a.PB(nums[i]);
    }

    sort(ALL(a));
    UNIQUE(a);

    for(int i = 0; i < N; i++)
        nums[i] = POS(a, nums[i]);

    int L, R;

    for(int i = 0; i < M; i++)
    {
        cin >> L >> R;

        queries.EB(L, R, i);
    }

    sort(ALL(queries));

    int A = 1, B = 0;

    //[A, B]

    for(auto &q : queries)
    {
        int L = q.L - 1;
        int R = q.R - 1;
        int i = q.i;


        while(A < L) remove(A++);
        while(A > L) add(--A);


        while(B < R) add(++B);
        while(B > R) remove(B--);

        ans[i] = curr;
    }

    for(int i = 0; i < M; i++)
        cout << ans[i] << endl;

	return 0;
}