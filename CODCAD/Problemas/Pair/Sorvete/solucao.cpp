#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compara(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}

int main(int argc, char const *argv[])
{
	int P, S, x, y;
	cin >> P >> S;
	vector<pair<int, int> > sorveteiros;
	for (int i = 0; i < S; ++i)
	{
		cin >> x >> y;
		sorveteiros.push_back(make_pair(x, y));
	}

	sort(sorveteiros.begin(), sorveteiros.end(), compara);
	int inicio = sorveteiros[0].first;
	int fim = sorveteiros[0].second;
	for (int i = 1; i < S; ++i)
	{
		if(fim < sorveteiros[i].first){
			cout << inicio << ' ' << fim << endl;
			inicio = sorveteiros[i].first;
			fim = sorveteiros[i].second;
		}else{
			fim = max(sorveteiros[i].second, fim);
		}
	}
	cout << inicio << ' ' << fim << "\n\n";
	return 0;
}