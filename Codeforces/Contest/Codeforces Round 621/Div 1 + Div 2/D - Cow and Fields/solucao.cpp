//https://codeforces.com/contest/1307/problem/D
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define INF 2000000020
#define MAXN 200020

using namespace std;

int N, M, K;
bool especiais[MAXN];

vector<int> grafo[MAXN];
int vai[MAXN], vem[MAXN];

void Dijkstra(int dist[], int orig)
{
	priority_queue<pii, vector<pii>, greater<pii> > pq;

	for(int i = 0; i < MAXN; i++) dist[i] = INF;

	dist[orig] = 0;
	pq.push(pii(0, orig));

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for(auto v : grafo[u])
			if(dist[v] > dist[u] + 1)
			{
				dist[v] = dist[u] + 1;
				pq.push(pii(dist[v], v));
			}
	}
}

int solve()
{
	vector<pii> nums;
	for(int i = 1; i <= N; i++)
		if(especiais[i])
			nums.push_back(pii(vai[i], i));

	sort(nums.begin(), nums.end());

	int ans = 0;

	for(int i = 1; i < (int)nums.size(); i++)
		ans = max(ans, vai[nums[i - 1].second] + vem[nums[i].second] + 1);

	return min(vai[N], ans);
}

int main(int argc, char const *argv[])
{
	optimize;

	int u, v, x;

	cin >> N >> M >> K;

	for(int i = 0; i < K; i++)
	{
		cin >> x;
		especiais[x] = true;
	}

	for(int i = 0; i < M; i++)
	{
		cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}

	Dijkstra(vai, 1);
	Dijkstra(vem, N);

	cout << solve() << endl;

	return 0;
}