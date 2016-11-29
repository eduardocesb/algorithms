#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int C, N;
	cin >> C >> N;
	vector<int> caixas;
	for (int i = 0; i < C; ++i)
	{
		caixas.push_back(0);
	}
	int r = 0;
	for (int i = 0; i < N; ++i)
	{
		int E, D;
		cin >> E >> D;
		sort(caixas.begin(), caixas.end());
		int duracao = caixas[0] - E;
		caixas[0] += D;
		if(duracao > 20){
			r++;
		}
	}
	cout << r << endl;
	return 0;
}