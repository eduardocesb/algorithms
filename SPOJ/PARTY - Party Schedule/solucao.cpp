#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define INF 1000000000
#define ll long long
#define pii pair<int, int>
#define MAXN 110
#define MAXP 550

using namespace std;

struct Estado
{
	int happiness, cost;

	Estado(int h = 0, int c = 0)
	{
		happiness = h;
		cost = c;
	}

	bool operator < (Estado a) const
	{
		return happiness != a.happiness ? happiness < a.happiness : cost > a.cost;
	} 

	bool operator != (Estado a)
	{
		return happiness != a.happiness || cost != a.cost;
	}

	Estado operator + (Estado a) const
	{
		return Estado(happiness + a.happiness, cost + a.cost);
	}

	void print()
	{
		cout << cost << " " << happiness << endl;
	}
};

int custo[MAXN], beneficio[MAXN], N, P;
Estado dp[MAXN][MAXP];
Estado null = Estado(-INF, -INF);

Estado solve(int i, int dinheiro)
{
	if(dinheiro <= 0 || i >= N) return Estado(0, 0);
	if(dp[i][dinheiro] != null) return dp[i][dinheiro];

	Estado nao_coloca = solve(i + 1, dinheiro);
	Estado coloca = null;

	if(dinheiro >= custo[i])
		coloca = Estado(beneficio[i], custo[i]) +  solve(i + 1, dinheiro - custo[i]);

	return dp[i][dinheiro] = max(coloca, nao_coloca);
}

void reset()
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j <= P; j++)
			dp[i][j] = null;
}

int main(int argc, char const *argv[])
{
	optimize;

	while((cin >> P >> N) && (P || N))
	{
		for(int i = 0; i < N; i++)
			cin >> custo[i] >> beneficio[i];

		reset();

		solve(0, P).print();
	}

	return 0;
}