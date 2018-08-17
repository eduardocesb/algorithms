#include <stdio.h>
int main(){
	int i;
	scanf("%d", &i);
	int j = 2, r = 1;
	while(j <= i){
		j *= 2;
		r *=4;
	}
	printf("%d", r);
	
	return 0;
}
