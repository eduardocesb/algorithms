#include <stdio.h>
int main(){
	int i, x;
	i = 0;
	while(1){
		scanf("%d", &i);
		if(i == 0){
			break;
		}else{
		 	if(i >= x){
				x = i;
			}
		}
	}
	printf("%d", x);
	
	return 0;
}
