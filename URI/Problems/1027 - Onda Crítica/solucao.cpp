#include <bits/stdc++.h>
#define INFINITO 10000000

using namespace std;

int solve(vector<int> a, vector<int> b)
{
	//Caso um dos vetores sejam vazios...
	if(!a.size() || !b.size()) return (a.size() + b.size());

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int tami = a.size(), tamj = b.size();

	int r1 = 0, i = 0, j = 0, ultimo = 0, anterior = -INFINITO;

	while(true)
	{
		if(ultimo)
		{
			while(i < tami && a[i] <= anterior) i++;

			if(i == tami) break;

			r1++;
			anterior = a[i];
			ultimo = 0;
		}
		else
		{
			while(j < tamj && b[j] <= anterior) j++;

			if(j == tamj) break;

			r1++;
			anterior = b[j];
			ultimo = 1;
		}
	}

	int r2 = 0;
	i = 0, j = 0, ultimo = 1, anterior = -INFINITO;

	while(true)
	{
		if(ultimo)
		{
			while(i < tami && a[i] <= anterior) i++;

			if(i == tami) break;

			r2++;
			anterior = a[i];
			ultimo = 0;
		}
		else
		{
			while(j < tamj && b[j] <= anterior) j++;

			if(j == tamj) break;

			r2++;
			anterior = b[j];
			ultimo = 1;
		}
	}

	return max(r1, r2);
}

int main(int argc, char** argv)
{
	int N, x, y;

	while(scanf("%d", &N) == 1)
	{
		map<int, vector<int> > idx;

		for(int i = 0; i < N; i++)
		{
			scanf("%d %d", &x, &y);
			idx[y].push_back(x);
		}

		int r = N > 0;

for(auto v : idx)
			if(idx.find(v.first + 2) != idx.end())
				r = max(r, solve(v.second, idx[v.first + 2]));

		printf("%d\n", r);
	}

	return 0;
}
