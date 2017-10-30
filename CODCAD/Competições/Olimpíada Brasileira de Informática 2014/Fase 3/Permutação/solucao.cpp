#include <bits/stdc++.h>
	#define optimize std::ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 1001000

using namespace std;
int N;
int s1[MAXN], s2[MAXN], prefixo[MAXN][2], sufixo[MAXN][2];
bool resposta[MAXN];

void precalc(){
	int inicio = 0, fim = N + 1;

	sufixo[N + 1][0] = inicio;
	sufixo[N + 1][1] = fim;

	//Calculo o sufixo de cada posicao...
	for (int i = N; i > 1; --i)
	{
		//Caso sejam iguais, todos os valores que poderam ser retirados sao maiores que ele...
		//Pois assim nao ira alterar o mesmo...
		if(s1[i] == s2[i - 1])
			inicio = max(inicio, s1[i]);
		//Caso s1[i] seja um valor a mais, todos os valores que poderam ser retirados sao menores que ele...
		//Pois assim ira diminuir em uma casa o valor do mesmo, deixando assim os dois iguais...
		else if(s1[i] - 1 == s2[i - 1])
			fim = min(fim, s1[i] - 1);
		//Se nao, nao existe nenhum valor que satisfaca a condicao...
		else
			inicio = fim = -1;

		//Por fim atualizo o intervalo que satisfaz o mesmo...
		sufixo[i][0] = inicio;
		sufixo[i][1] = fim;
	}

	inicio = 0, fim = N + 1;
	prefixo[0][0] = inicio;
	prefixo[0][1] = fim;

	//Calculo o prefixo de cada posicao...
	for (int i = 1; i <= N; ++i)
	{
		//Caso sejam iguais, todos os valores que poderam ser retirados sao maiores que ele...
		//Pois assim nao ira alterar o mesmo...
		if(s1[i] == s2[i])
			inicio = max(inicio, s1[i] + 1);	
		//Caso s1[i] seja um valor a mais, todos os valores que poderam ser retirados sao menores que ele...
		//Pois assim ira diminuir em uma casa o valor do mesmo, deixando assim os dois iguais...
		else if(s1[i] - 1 == s2[i])
			fim = min(fim, s1[i] - 1);
		//Se nao, nao existe nenhum valor que satisfaca a condicao...
		else
			inicio = fim = -1;

		//Por fim atualizo o intervalo que satisfaz o mesmo...
		prefixo[i][0] = inicio;
		prefixo[i][1] = fim;
	}
}

//Verifica se um determinado valor 'x' da posicao 'i' pode ser utilizado como resposta...
bool da_certo(int x, int i){
	return (prefixo[i - 1][0] <= x && x <= prefixo[i - 1][1]) && (sufixo[i + 1][0] <= x && x <= sufixo[i + 1][1]);
}

//Calcula quais os possiveis valores para a resposta...
void solve(){
	for (int i = 1; i <= N; ++i)
		resposta[s1[i]] = da_certo(s1[i], i);
}

int main(int argc, char const *argv[])
{
	optimize;

	cin >> N;

	for (int i = 1; i <= N; ++i) cin >> s1[i];
	for (int i = 1; i < N; ++i) cin >> s2[i];

	precalc();

	solve();

	for (int i = 1; i <= N; ++i)
		if(resposta[i])
			cout << i << ' ';

	cout << endl;

	return 0;
}