#include <bits/stdc++.h>

using namespace std;

int nums[60];

int menor(vector<int> v)
{
	int m = 100, tam = v.size();

	bool ok = true;

	for(int i = 1; i < tam; i++)
		ok *= v[i] == v[i - 1];

	if(ok) return -1;

	for(int i = 0; i < tam; i++)
		m = min(m, v[i]);

	return m;
}

int main(int argc, char** argv)
{
	int N;

	while((cin >> N) && N)
	{
		string nomes[N];

		for(int i = 0; i < N; i++) cin >> nomes[i];


		for(int i = 0; i < 52; i++) cin >> nums[i];

		bool marcado[N];
		memset(marcado, 0, sizeof marcado);
		int marcados = 0;

		for(int i = 0; i < 52;)
		{
			if(N - marcados > 51 - i)
				break;
			if(marcados == N - 1) break;

			vector<int> x;

			for(int j = 0; j < N - marcados; j++)
				x.push_back(nums[j + i]);

			i += N - marcados;

			int m = menor(x);

			if(m == -1) break;
			
			int j = 0;

			for(int k = 0; k < N; k++)
			{
				if(marcado[k]) continue;
				if(m == x[j++])
				{
					marcado[k] = true;
					marcados++;
				}
			}

		}

		for(int i = 0; i < N; i++)
			if(!marcado[i])
				cout << nomes[i] << " ";

		cout << endl;
	}

	return 0;
}
