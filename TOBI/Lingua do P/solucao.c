#include <stdio.h>
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if((a*b) == (c*d)){
		printf("S");
	}else if((a*c) == (b*d)){
		printf("S");
	}else if((a*d) == (b*c)){
		printf("S");
	}else{
		printf("N");
	}
	
	return 0;
}
