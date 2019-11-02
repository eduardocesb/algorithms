#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 1000000000
#define MAXN 220

using namespace std;

vector<string> palavras;
int dist[MAXN][MAXN], N;
map<string, int> mapa;

void reset()
{
	palavras.clear();
	mapa.clear();
	N = 0;

	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXN; j++)
			dist[i][j] = (i == j) ? 0 : INF;
}

int diferenca(string u, string v)
{
	if(u.size() != v.size()) return INF;

	int ans = 0;

	for(int i = 0; i < (int)u.size(); i++)
		ans += u[i] != v[i];

	return ans;
}

void precalc()
{
	N = palavras.size();

	for(int i = 0; i < N; i++) mapa[palavras[i]] = i;

	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++)
			if(diferenca(palavras[i], palavras[j]) == 1)
				dist[i][j] = dist[j][i] = 1;

	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int solve(string u, string v)
{
	return dist[mapa[u]][mapa[v]];
}

int main(int argc, char const *argv[])
{
	optimize;

	int T;

	string u, v, linha;

	cin >> T;

	getline(cin, linha);
	
	bool ok = false;

	while(T--)
	{
		if(ok) cout << endl;
		ok = true;

		reset();

		while(getline(cin, linha) && (linha != "*")) palavras.push_back(linha);

		precalc();


		while(!cin.eof())
		{
			getline(cin, linha);

			if(linha == "") break;

			int i = 0, tam = linha.size();

			u = v = "";

			while(linha[i] != ' ') u += linha[i++];
			i++;
			while(i < tam) v += linha[i++];

			cout << u << " " << v << " " << solve(u, v) << endl;
		}
	}

	return 0;
}
