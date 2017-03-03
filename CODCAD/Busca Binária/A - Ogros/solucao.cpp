#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m, x;
	vector<int>::iterator it;
	cin >> n >> m;
	vector<int> faixa;
	map<int, int> premiacoes;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> x;
		faixa.push_back(x);
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		premiacoes[i] = x;
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> x;
		it = upper_bound(faixa.begin(), faixa.end(), x);
		cout << premiacoes[it - faixa.begin()] << " ";
	}
	cout << endl;
	return 0;
}