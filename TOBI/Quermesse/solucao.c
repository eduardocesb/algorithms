#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int i, x, r;
	int j=1;
	while(n!=0){
		for(i=0;i<n;i++){
			scanf("%d", &x);
			if(x == (i+1)){
				r = x;
			}
		}
		printf("Teste %d\n", j);
		printf("%d\n", r);
		printf("\n");
		
		scanf("%d", &n);
		j += 1;
	}
	return 0;
}
