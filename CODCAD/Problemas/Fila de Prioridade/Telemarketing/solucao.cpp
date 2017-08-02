#include <bits/stdc++.h>
//Por simplicidade...
#define MP make_pair
//Por simplicidade digo que um vendedor é um pair<int, int>
//Onde vendedor.first é a hora que o vendedor ficou livre
//E vendedor.second é de qual vendedor estou falando...
#define vendedor pair<int, int>

using namespace std;

int main(int argc, char const *argv[])
{
	//Fila que vai guardar o horário que o vendedor i vai estar livre...
	//vededores.first é o horário que o vendedor vededores.second vai estar livre...
	priority_queue<vendedor, vector<vendedor>, greater<vendedor> > vendedores;
	
	//Variaveis que vou utilizar...	
	int N, L, T, D;
	cin >> N >> L;

	//Vetor que vai guardar quantas ligações cada vendedor atendeu...
	int quantidade_ligacoes[N];

	//Inicialmente todos os vendedores começam livres e nenhum atendeu nenhuma ligação...
	for (int i = 0; i < N; quantidade_ligacoes[i++] = 0)
		vendedores.push(MP(0, i));

	//Para cada ligação...
	for (int i = 0; i < L; ++i)
	{
		//Leio a duração da i-ésima ligação...
		cin >> D;

		//Pego qual o vendedor está livre primeiro...
		vendedor livre = vendedores.top();

		//Removo o vendedor da fila...
		vendedores.pop();

		//Aumento em uma unidade a quantidade de ligações do vendedor que atendeu a ligação...
		quantidade_ligacoes[livre.second]++;

		//Atualizo o novo horário em que o vendedor que atendeu a ligação vai estar livre...
		//Em que esse novo horário vai ser o horário que ele desocupou mais a duração da ligação...
		livre.first += D;

		//Adiciono novamente esse vendedor na fila...
		vendedores.push(livre);
	}

	//Para cada vendedor, imprimo quantas ligações cada um atendeu...
	for (int i = 0; i < N; ++i)
		cout << i + 1 << ' ' << quantidade_ligacoes[i] << endl;
	return 0;
}