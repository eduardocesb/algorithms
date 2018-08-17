#include <stdio.h>
int main(){

	int n;
	scanf("%d", &n);
	int vet[n];
	int max, at;
	int i;
	max = 0;
	at = 1;
	for(i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	for(i=0; i<n-1; i++){
		if(vet[i] == vet[i+1]){
			at = at + 1;
			if(at > max){
				max = at;
			}
		}else{
		at = 1;
		}
	}
	printf("%d", max);
	return 0;
}
