#include <iostream>
#include <map>
#include <cstdio>

using namespace std;


int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	char x;
	scanf("%c", &x);
	scanf("%c", &x);
	bool imprime = false;
	for (int i = 0; i < N; ++i)
	{
		map<string, string> arvores;
		map<string, int> qtd;
		string arvore;
		getline(cin, arvore);
		int quantidade = 0;
		while(arvore[0] != '\0'){
			quantidade++;
			arvores[arvore] = arvore;
			qtd[arvore]++;
			getline(cin, arvore);
		}

		map<string, string>::iterator it;
		for(it = arvores.begin(); it != arvores.end(); it++){
			cout << it->second << " ";
			int q = qtd[it->second];
			double p = (100.0 * q)  / quantidade;
			printf("%.4f\n", p);
		}
		if(i != N-1){
			cout << endl;
		}
	}
	return 0;
}