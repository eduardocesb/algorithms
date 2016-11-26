#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	map<int, int> casas;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		casas[x] = i;
	}
	int da_vez = 0, r = 0;
	for (int i = 0; i < M; ++i)
	{
		int x;
		cin >> x;
		int dist = da_vez - casas[x];
		if(dist < 0)
		{
			dist *= -1;
		}
		r += dist;

		da_vez = casas[x];
	}

	cout << r << endl;
	return 0;
}