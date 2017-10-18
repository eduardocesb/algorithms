#include <bits/stdc++.h>
#define MAXN 1010
#define MAXR 1000010

using namespace std;

int N;
pair<int, int> caixas[MAXN];

unordered_map<int, int> DP[MAXN];

int solve(int i, int r){
	//Caso eu não possa colocar aquela caixa...
	if(r < 0) return -1;
	//Caso não tenha mais caixas disponiveis ou
	//Não tenha mais resistencia...
	if(i < 0 || !r) return 0;
	//Caso já tenha calculado esse valor...
	if(DP[i].find(r) != DP[i].end()) return DP[i][r];

	//Se não retorna o máximo entre colocar e não colocar a 'i'-ésima caixa...
	//E guarda na tabela DP para reaproveitar depois...
	return DP[i][r] = max(solve(i - 1, min(r, caixas[i].first) - caixas[i].second) + 1, solve(i - 1, r));
}

int main(int argc, char const *argv[])
{

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> caixas[i].second >> caixas[i].first;

	sort(caixas, caixas + N);

	cout << solve(N - 1, MAXR) << endl;
	return 0;
}