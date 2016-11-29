#include <cstdio>

int vetor[100000];
int p[1000000];
int n;

int busca_binaria(int forca){
	int ini = 0, fim  = n;
	while(fim-ini > 1){
		int med = (fim + ini)/2;
		if(vetor[med] <= forca){
			ini = med;
		}
		else{
			fim = med;
		}
	}
	return p[fim-1];
}

int main(){
	int m;
	scanf("%d %d", &n, &m);
	for(int i=1;i<n;i++){
		scanf("%d", &vetor[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d", &p[i]);
	}
	for(int i=0;i<m;i++){
		int y;
		scanf("%d", &y);
		int r = busca_binaria(y);
		printf("%d ", r);
	}
	return 0;
}
