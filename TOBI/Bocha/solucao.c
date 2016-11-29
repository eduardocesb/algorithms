#include <stdio.h>
int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);	
	int r;
	if((a > b && a < c ) || (a > c && a <b)){
		r = a;
	}else{
		if((b > a && b < c) || (b > c && b < a)){
			r = b;
		}else{
		r = c;
		}
	}
		
	
	
	printf("%d", r);
	
	
	return 0;
}
