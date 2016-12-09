#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, D;
	cin >> N >> D;
	while(N != 0 || D != 0){
		int x;
		cin >> x;
		stringstream str;
		str << x;
		string num = str.str();
		int qtd = 0;
		while(qtd < D){
			int menor = 9;
			int posicao;
			int tam = num.size();
			for (int i = 0; i < tam; ++i)
			{
				if(menor > num[i] || i == 0){
					menor = int(num[i]);
					posicao = i;
				}
			}
			qtd++;
			num.erase(num.begin() + posicao);
		}
		cout << num << endl;
		cin >> N >> D;
	}
	return 0;
}