#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	map<string, string> nomes;
	int comportadas = 0, nao_comportadas = 0;
	for (int i = 0; i < N; ++i)
	{
		char c;
		string nome;
		cin >> c >> nome;
		nomes[nome] = nome;
		if(c == '+'){
			comportadas++;
		}else{
			nao_comportadas++;
		}
	}
	map<string, string>::iterator it;
	for(it = nomes.begin(); it != nomes.end(); it++){
		cout << it->second << endl;
	}
	cout << "Se comportaram: " << comportadas << " | Nao se comportaram: " << nao_comportadas << endl;
	return 0;
}