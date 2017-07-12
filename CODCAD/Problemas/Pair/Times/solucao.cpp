#include <iostream>
#include <algorithm>

using namespace std;

bool compara(pair<int, string> a, pair<int, string> b){
	return a.first > b.first;
}

bool compara_nome(pair<int, string> a, pair<int, string> b){
	return a.second < b.second;
}

int main(int argc, char const *argv[])
{
	int N, T, H;
	string nome;
	cin >> N >> T;
	pair<int, string> alunos[N];
	pair<int, string> time[(N / T) + 1];

	for (int i = 0; i < N; ++i)
	{
		cin >> nome >> H;
		alunos[i] = make_pair(H, nome);
	}
	sort(alunos, alunos + N, compara);	

	for (int i = 0; i < T; ++i)
	{
		int indice = 0;
		for (int j = i; j < N; j += T)
		{
			time[indice] = alunos[j];
			indice++;
		}
		sort(time, time + indice, compara_nome);
		cout << "Time " << i + 1 << endl;
		indice = 0;
		for (int j = i; j < N; j += T)
		{
			cout << time[indice].second << endl;
			indice++;
		}
		cout << endl;
	}
	return 0;
}