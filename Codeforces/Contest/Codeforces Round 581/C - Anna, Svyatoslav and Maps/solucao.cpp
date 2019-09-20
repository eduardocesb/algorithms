#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define INF 1000000000
#define MAXN 110

using namespace std;

int N, M;
vector<int> vertices;

int dist[MAXN][MAXN];

void precalc()
{
	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void solve()
{
	if(M == 2)
	{
		cout << 2 << endl;
		cout << vertices[0] << " " << vertices[1] << endl;
		return;
	}

	precalc();

	deque<int> r;

	r.push_back(vertices[0]);

	int tam = 2, davez = 2;

	int u = vertices[0];

	while(davez < M)
	{
		if(dist[u][vertices[davez]] != tam)
		{
			u = vertices[davez - 1];
			r.push_back(u);
			tam = 1;
		}

		tam++;
		davez++;
	}

	r.push_back(vertices[M - 1]);

	cout << (int)r.size() << endl;
	for(auto u : r)
		cout << u << " ";
	cout << endl;
}

int main(int argc, char** argv)
{
	optimize;

	char x;

	cin >> N;

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
		{
			cin >> x;
			dist[i][j] = x == '1' ? 1 : i == j ? 0 : INF;
		}

	int u;

	cin >> M;

	for(int i = 0; i < M; i++)
	{
		cin >> u;
		vertices.push_back(u);
	}

	solve();

	return 0;
}
