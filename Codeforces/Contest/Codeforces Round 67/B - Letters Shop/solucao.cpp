#include <bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

struct Mapa
{
	vector<int> letra[27];

	void add(int pos, int i)
	{
		letra[pos].push_back(i);
	}

	int query(int pos, int qtd)
	{
		return letra[pos][qtd];
	}
};

int main(int argc, char const *argv[])
{
	optimize;

	Mapa mapa;

	int N, T;
	string S;

	cin >> N >> S;

	for(int i = 0; i < N; i++)
		mapa.add(S[i] - 'a', i);

	cin >> T;

	while(T--)
	{
		cin >> S;

		int tam = S.length();

		unordered_map<char, int> letras;

		for(int i = 0; i < tam; i++)
			letras[S[i]]++;

		int r = 0;

		for(auto x : letras)
			r = max(r, mapa.query(x.first - 'a', x.second - 1));

		cout << r + 1 << endl;
	}

	return 0;
}