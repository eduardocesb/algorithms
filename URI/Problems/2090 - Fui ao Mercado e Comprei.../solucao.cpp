#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	while(N != 0 || M != 0){
		unordered_map<int, string> palavras;
		for (int i = 1; i <= N; ++i)
		{
			string x;
			cin >> x;
			palavras[i] = x;
		}

		int cont = 0, incremento = 1, r = 0;
		while(cont + incremento < M){
			cont += incremento;
			incremento++;
		}
		r = M - cont;
		cout << palavras[r] << endl;
		cin >> N >> M;
	}
	return 0;
}