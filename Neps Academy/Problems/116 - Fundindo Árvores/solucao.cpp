//https://neps.academy/problem/116
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
	int filhos[3];

	Node(int a = 0, int b = 0, int c = 0)
	{
		filhos[0] = a;
		filhos[1] = b;
		filhos[2] = c;
	}
};

Node esquerda[MAXN], direita[MAXN];

int N, M;

//Maior caminho central de uma arvore 
int dfs(Node *arvore, int u, int best)
{
	if(!u) return best;

	int ans = best + 1;

	for(int i = 0; i < 3; i++)
		ans = max(ans, dfs(arvore, arvore[u].filhos[i] , (i == 1) ? (best + 1) : 0));

	return ans;
}

int solve()
{
	int pref_esq = 0, pref_dir = 0;

	int u = 1;

	while(u)
	{
		pref_esq++;
		u = esquerda[u].filhos[1];
	}

	u = 1;

	while(u)
	{
		pref_dir++;
		u = direita[u].filhos[1];
	}

	int ans = max(min(pref_esq, dfs(direita, 1, 0)), min(pref_dir, dfs(esquerda, 1, 0)));


	return (N + M) - ans;
}

int main(int argc, char const *argv[])
{
	optimize;
	
	cin >> N;

	int a, b, c;

	for(int i = 1; i <= N; i++)
	{
		cin >> a >> b >> c;

		esquerda[a] = Node(b, c, 0);
	}

	cin >> M;

	for(int i = 1; i <= M; i++)
	{
		cin >> a >> b >> c;

		direita[a] = Node(0, b, c);
	}

	cout << solve() << endl;

	return 0;
}