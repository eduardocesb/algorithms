#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> M >> N;
	map<string, int> palavras;
	string palavra;
	for (int i = 0; i < M; ++i)
	{
		int n;
		cin >> palavra >> n;
		palavras[palavra] = n;
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> palavra;
		int r = 0;
		while(palavra[0] != '.'){
			r += palavras[palavra];
			cin >> palavra;
		}
		cout << r << endl;
	}
	return 0;
}