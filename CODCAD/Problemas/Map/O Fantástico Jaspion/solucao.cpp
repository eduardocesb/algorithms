#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, M, N;
	string j, p;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		map<string, string> dicionario;
		scanf(" %d %d ", &M, &N);
		for (int k = 0; k < M; ++k)
		{
			getline(cin, j);
			getline(cin, p);
			dicionario[j] = p;
		}

		for (int k = 0; k < N; ++k)
		{
			char x;
			j = "";
			while(scanf("%c", &x)){
				if(x == ' ' || x == '\n'){
					if(dicionario.find(j) != dicionario.end()){
						cout << dicionario[j] << ' ';
						j = "";
					}else{
						cout << j << ' ';
						j = "";
					}
				}else
					j += x;
				if(x == '\n')
					break;
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}