#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, maior = 0, atual = 0;
	cin >> N;
	string linha;
	for (int i = 0; i < N; ++i)
	{
		cin >> linha;
		if(i%2==0){
			for (int j = 0; j < N; ++j)
			{
				if(linha[j] == 'o'){
					atual++;
					if(atual > maior){
						maior = atual;
					}
				}else if(linha[j] == 'A'){
					atual = 0;
				}
			}
		}else{
			for (int j = N-1; j >= 0; j--)
			{
				if(linha[j] == 'o'){
					atual++;
					if(atual > maior){
						maior = atual;
					}
				}else if(linha[j] == 'A'){
					atual = 0;
				}
			}
		}
	}

	cout << maior << endl;
	return 0;
}