#include <stdio.h>
int main(){
	int i, max;
	scanf("%d%d", &i, &max);
	int saiu[i];
	int entrou[i];
	int q;
	int x;
	q = 0;
	int r = 0;
	for(x=0; x<i ; x++){
		scanf("%d%d", &saiu[x], &entrou[x]);
	}
	for(x=0; x<i ; x++){
		q = q - saiu[x];
		q = q + entrou[x];
		if(q>max){
			r =1;
		}
	}
	if(r == 1){
		printf("S");
	}else{
		printf("N");
	}
	

	return 0;
}
