#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, D;
	//Leio 'N' e 'D' até que elese sejam iguais a '0'...
	while((cin >> N >> D) && N != 0 || D != 0){
		char x;
		char pilha[N];
		int topo = 0;
		int apagados = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> x;
			while((topo != 0) && (pilha[topo - 1] < x) && (apagados < D)){
				topo--;
				apagados++;
			}
			if(topo < N - D)
				pilha[topo++] = x;
		}
		pilha[topo] = '\0';
		cout << pilha << endl;
	}
	return 0;
}