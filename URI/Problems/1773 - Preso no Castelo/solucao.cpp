#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define INF 1000000000
#define MAXN 1010


using namespace std;

vector<int> grafo[MAXN], chaves[MAXN];
int N, M;
bool ta_com_a_chave[MAXN], visitados[MAXN], pendente[MAXN];

void reset()
{
	for(int i = 1; i <= N; i++)
	{
		pendente[i] = visitados[i] = ta_com_a_chave[i] = false;
		grafo[i].clear();
		chaves[i].clear();
	}
}

bool ok()
{
	queue<int> fila;

	fila.push(1);

	int vis = 0, u;
	ta_com_a_chave[1] = true;

	while(!fila.empty())
	{
		u = fila.front();
		fila.pop();

		if(!ta_com_a_chave[u])
		{
			// cout << "-- " << u << endl;
			return false;
		}

		if(visitados[u]) continue;

		visitados[u] = true;

		for(auto v : chaves[u]) 
		{
			if(pendente[v] && !visitados[v])
				fila.push(v);
			ta_com_a_chave[v] = true;
		}

		vis++;

		for(auto v : grafo[u])
			if(!visitados[v])
			{
				if(ta_com_a_chave[v])
					fila.push(v);
				else
					pendente[v] = true;
			}
	}

	return vis == N;
}

int main(int argc, char const *argv[])
{
	optimize;

	int a, b;
	
	while(!cin.eof() && (cin >> N >> M))
	{
		reset();

		for(int i = 0; i < M; i++)
		{
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}

		for(int i = 2; i <= N; i++)
		{
			cin >> a;
			chaves[a].push_back(i);
		}

		cout << (ok() ? "sim" : "nao") << endl;
	}

	return 0;
}