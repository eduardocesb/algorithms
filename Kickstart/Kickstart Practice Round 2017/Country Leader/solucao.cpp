#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)
#define pii pair<int, string>

using namespace std;

bool compara(pii &a, pii &b)
{
	if(a.first != b.first)
		return a.first > b.first;
	return a.second < b.second;
}

int main(int argc, char const *argv[])
{
	//optimize;

	int T, N;
	char x;

	scanf("%d", &T);

	for (int i = 1; i <= T; ++i)
	{
		scanf("%d", &N);
		scanf("%c", &x);

		pair<int, string> pais[N];

		for (int j = 0; j < N; ++j)
		{
			int pontos = 0;
			boo	l existe[30];
			memset(existe, 0, sizeof(existe));

			string nome = "";

			while(scanf("%c", &x) && x != '\n')
			{
				nome += x;
				if(x == ' ') continue;
				pontos += 1 - existe[x - 'A'];
				existe[x - 'A'] = true;
			}

			pais[j] = make_pair(pontos, nome);
		}

		sort(pais, pais + N, compara);

		printf("Case #%d: %s\n", i, pais[0].second.c_str());
	}

	return 0;
}