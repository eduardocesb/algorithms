#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 2020

using namespace std;

int n, s, peso[MAXN], valor[MAXN], tab[MAXN][MAXN]; // declaro as variáveis que vou usar

// declaro a função da d, de nome knapsack
// o estado da dp será definido pelo objeto a ser verificado e o quanto a mochila ainda aguenta
int knapsack(int obj, int aguenta){
	
	// se já calculamos esse estado da dp, retornamos o resultado salvo
	if(tab[obj][aguenta]>=0) return tab[obj][aguenta];
	
	// se não houver mais objetos ou espaço na mochila, retorno 0, pois não posso mais botar nada
	if(obj>n || !aguenta) return tab[obj][aguenta]=0;
	
	// não colocar avança para o estado em que tentmos o próximo, com o mesmo espaço disponível
	int nao_coloca=knapsack(obj+1, aguenta);
	
	// se for possível colocar o objeto
	if(peso[obj]<=aguenta){
		
		// o melhor atingível é o valor dele mais o melhor entre colocar ou não os próximos
		// que é o resultado do estado da dp em que olhamos o próximo objeto
		// mas agora a mpchila aguenta o que aguentava antes menos o peso que coloquei nela
		int coloca=valor[obj]+knapsack(obj+1, aguenta-peso[obj]);
		
		// e a função deve retornar o melhor entre colocar ou não colocar
		return tab[obj][aguenta]=max(coloca, nao_coloca);
	}
	
	// se a função não retornou ainda, então ela não entrou no if
	// logo não era possível colocar o objeto 
	return tab[obj][aguenta]=nao_coloca; // então retorno o valor de não colocá-lo
}

int main(){
	
	memset(tab, -1, sizeof(tab)); // marco todos os estados da dp como não calculados
	
	scanf("%d %d", &s, &n); // leio o s valores de s e n
	
	// leios os valores e pesos dos objetos
	for(int i=1; i<=n; i++) scanf("%d %d", &peso[i], &valor[i]);
	
	// e imprimo o maior valor que o ladrão pode roubar
	// se ele escolher colocar ou não todos os objetos a partir do primeiro
	// e a mochila ainda aguentar todo o valor de s
	printf("%d\n", knapsack(1, s)); // que é o estado (1, s) da dp
	
	return 0;
}
