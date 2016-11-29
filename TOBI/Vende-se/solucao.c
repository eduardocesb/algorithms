#include <stdio.h>

int main(){
	int N, K;
	scanf("%d %d",&N, &K);
	int pilha[N];
	int i;
	for(i=0;i <N;i++){
		scanf("%d", &pilha[i]);
	}	
	int j;
	int aux;
	for(i=N-1;i>=0;i--){
		for(j=0;j<i;j++){
			if(pilha[i] < pilha[j]){
				aux = pilha[i];
				pilha[i] = pilha[j];
				pilha[j] = aux;
			}
		}
	}
	int x = N-K;
	int r;
	for(i=0;i<x-2;i++){
			if(r > (pilha[i+1] - pilha[i]) || i == 0){
				r = (pilha[i+1] - pilha[i]);
			}
	}
	printf("%d", r);
	return 0;
}
