#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 100010

using namespace std;

vector<int> arvore[6 * MAXN];
vector<int> a(MAXN), v;
int N, M, A, B, K;

void build(int no, int i, int j)
{
	if(i == j)
	{
		arvore[no].push_back(a[i]);
		return;
	}

	int e = 2 * no;
	int d = e + 1;
	int m = (i + j) / 2;

	build(e, i    , m);
	build(d, m + 1, j);

	merge(arvore[e].begin(), arvore[e].end(), arvore[d].begin(), arvore[d].end(), back_inserter(arvore[no]));
}

int query(int no, int i, int j, int A, int B, int k)
{
	if(B < i || j < A) return 0;
	if(A <= i && j <= B)
		return upper_bound(arvore[no].begin(), arvore[no].end(), k) - arvore[no].begin();

	int e = 2 * no;
	int d = e + 1;
	int m = (i + j) / 2;

	return query(e, i, m, A, B, k) + query(d, m + 1, j, A, B, k);
}

int binary_search()
{
	int inicio = 1, fim = N, meio, r;

	while(inicio <= fim)
	{
		meio = (inicio + fim) / 2;

		int x = query(1, 1, N, A, B, meio);

		if(x >= K)
			r = meio, fim = meio - 1;
		else
			inicio = meio + 1;
	}

	return r;
}

int main(int argc, char** argv)
{
	optimize;

	cin >> N >> M;

	for(int i = 1; i <= N; i++)
	{
		cin >> a[i];
		v.push_back(a[i]);
	}

	sort(v.begin(), v.end());

	for(int i = 1; i <= N; i++)
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;

	build(1, 1, N);

	for(int i = 0; i < M; i++)
	{
		cin >> A >> B >> K;

		cout << v[binary_search() - 1] << endl;
	}

	return 0;
}