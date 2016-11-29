#include <stdio.h>
int main(){

	float vet[5];
	int i;
	for(i=0; i<5; i++){
		scanf("%f",&vet[i]);
	}
	int j;
	float aux;
	for(i=4; i>=0; i--){
		for(j=0; j<=i-1; j++){
			if(vet[i]< vet[j]){
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
	}
	printf("%.1f",(vet[1]+vet[2]+vet[3]));
	return 0;
}
