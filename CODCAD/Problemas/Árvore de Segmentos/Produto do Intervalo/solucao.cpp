#include <bits/stdc++.h>
#define MAXN 2000100

using namespace std;

//Número de elementos e quantidade de operações...
int N, K;
//vetor com os números...
int nums[MAXN];
//Árvore segmentada...
int arvore[MAXN];

//Constoi a arvore...
void constroi(int no = 1, int i = 1, int j = N){
	//Se for um nó folha...
	if(i == j){
		//Adiciono o valor dele na arvore...
		arvore[no] = nums[i];
		return;
	}
	//Se não...
	//Pego o nó dos dois filhos dele...
	int filho_esquerda = 2 * no;
	int filho_direita = filho_esquerda + 1;
	int meio = (i + j) / 2;

	//Controi o filho da esquerda...
	constroi(filho_esquerda, i, meio);
	//Constroi o filho da direita...
	constroi(filho_direita, meio + 1, j);

	//Guardo na arvore o produto dos dois filhos...
	arvore[no] = arvore[filho_esquerda] * arvore[filho_direita];
}

//Muda a valor de um elemento...
void atualiza(int no, int i, int j, int posicao, int novo_valor){
	//Se encontrei a posição do elemento...
	if(i == j){
		//Atualizo os valores dos mesmos...
		nums[i] = arvore[no] = novo_valor;
		return;
	}

	//Se não..
	//Pego o nó dos filho do elemento...
	int filho_esquerda = 2 * no;
	int filho_direita = filho_esquerda + 1;
	int meio = (i + j) / 2;

	//Se a posição procurada tá para a esquerda...
	//Vou atualizar os elementos da esquerda...
	if(posicao <= meio) atualiza(filho_esquerda, i, meio, posicao, novo_valor);
	//Se não atualizo os elementos da direita...
	else atualiza(filho_direita, meio + 1, j, posicao, novo_valor);
	//No final mudo o valor no nó atual...
	arvore[no] = arvore[filho_esquerda] * arvore[filho_direita];
}

//Consulta o produto de um intervalo...
int consulta(int no, int i, int j, int A, int B){
	//Se o intervalo que estou estiver contido no que eu quero...
	//Retorno o valor daquele intervalo...
	if(i >= A && j <= B)
		return arvore[no];
	//Se eu estiver fora do intervalo desejado...
	//Saio da função e retorno o valor neutro para a multiplicação...
	if(i > B || j < A)
		return 1;

	//Pego o nó dos filhos...
	int filho_esquerda = 2 * no;
	int filho_direita = filho_esquerda + 1;
	int meio = (i + j) / 2;

	//Retorno o produto dos dois...
	return consulta(filho_esquerda, i, meio, A, B) * consulta(filho_direita, meio + 1, j, A, B);
}

int main(int argc, char const *argv[])
{
	while((cin >> N >> K) && (N != EOF || K != EOF)){
		//Leio os valores iniciais...
		for (int i = 1; i <= N; ++i){
			cin >> nums[i];
			//Como o que nos interessa é apenas se o produto é 
			//positivo, negativo ou zero, então não irei guardar apenas o valor que me dá 
			//o sinal...
			//Se o valor for negativo, não guardarei o valor exato
			//E sim o -1, que representa todos os números negativos...
			if(nums[i] < 0) nums[i] = -1;
			//Se o número for positivo, guardarei apenas o 1, que representa os valores positivos...
			else if(nums[i] > 0) nums[i] = 1;
			//o produto pode crescer muito e não ser possivel guardar nem em um long long...
			//Não guardarei os valres exatos, pois além de não ter necessidade, no final
		}
		
		//Constroi a arvore...
		constroi();

		char O;
		int I, V;
		//Para cada operação...
		for (int j = 0; j < K; ++j)
		{
			cin >> O >> I >> V;
			//Se for para atualizar, eu atualizo a posição I
			if(O == 'C'){
				if(V < 0) V = -1;
				else if(V > 0) V = 1;
				atualiza(1, 1, N, I, V);
				continue;
			}
			int r = consulta(1, 1, N, I, V);
			if(r < 0)
				cout << '-';
			else if(r == 0)
				cout << '0';
			else
				cout << '+';
		}
		cout << endl;
	}
	return 0;
}