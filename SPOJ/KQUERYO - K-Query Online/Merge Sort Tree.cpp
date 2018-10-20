#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 30300

using namespace std;

vector<int> arvore[6 * MAXN];
int nums[MAXN];

void build(int no, int i, int j)
{
	if(i == j)
	{
		arvore[no].push_back(nums[i]);
		return;
	}

	int e = 2 * no;
	int d = e + 1;
	int m = (i + j) / 2;

	build(e, i, m);
	build(d, m + 1, j);

	merge(arvore[e].begin(), arvore[e].end(), arvore[d].begin(), arvore[d].end(), back_inserter(arvore[no]));
}

int query(int no, int i, int j, int A, int B, int k)
{
	if(j < A || B < i || j < i) return 0;
	if(A <= i && j <= B)
		return arvore[no].end() - upper_bound(arvore[no].begin(), arvore[no].end(), k);

	int e = 2 * no;
	int d = e + 1;
	int m = (i + j) / 2;

	return query(e, i, m, A, B, k) + query(d, m + 1, j, A, B, k);
}

int main(int argc, char** argv)
{
	optimize;

	int N, Q, I, J, K;

	scanf("%d", &N);

	for(int i = 1; i <= N; i++)
		scanf("%d", &nums[i]);

	build(1, 1, N);

	scanf("%d", &Q);

	int last = 0;

	while(Q--)
	{
		scanf(" %d %d %d", &I, &J, &K);

		I ^= last;
		J ^= last;
		K ^= last;

		last = query(1, 1, N, I, J, K);

		printf("%d\n", last);
	}

	return 0;
}
