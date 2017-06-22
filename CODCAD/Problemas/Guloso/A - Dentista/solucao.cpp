#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool compara(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(int argc, char const *argv[])
{
	int n, inicio, fim, qtd = 0, livre = 0;
	vector<pair<int, int> > atendimentos;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> inicio >> fim;
		atendimentos.push_back(make_pair(inicio, fim));
	}

	sort(atendimentos.begin(), atendimentos.end(), compara);

	for (int i = 0; i < n; ++i)
	{
		if(atendimentos[i].first >= livre){
			qtd++;
			livre = atendimentos[i].second;
		}
	}

	cout << qtd << endl;
	return 0;
}