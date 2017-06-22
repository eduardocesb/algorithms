#include <iostream>
#include <algorithm>

using namespace std;

bool compara(pair<int,int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(int argc, char const *argv[])
{
	int n, inicio, fim, r = 0, atual = 0;
	cin >> n;
	pair<int, int>encomendas[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> inicio >> fim;
		encomendas[i] = make_pair(inicio, fim);
	}

	sort(encomendas, encomendas+n, compara);

	for (int i = 0; i < n; ++i)
	{
		r = max(0, atual + encomendas[i].first - encomendas[i].second);
		atual += encomendas[i].first;
	}

	cout << r << endl;
	return 0;
}