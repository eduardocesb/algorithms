#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int j = 1;
	int r=1;
	int i;
	while(n != 0){
		r = 1;
		printf("Teste %d\n", j);
		for(i=0;i<n;i++){
			r = r*2;
		}
		r = r-1;
		printf("%d\n", r);
		printf("\n");
		j +=1;
		scanf("%d", &n);
	}	

return 0;
}
