#include <stdio.h>
int main(){
	int max;
	scanf("%d", &max);
	int a;
	char x;
	char b;
	int c;
	scanf("%d%c%c%d", &a, &x, &b, &c);
	int r;
	if(b == '+'){
		r = a+c;
	}else{
			r = a*c;
	}
	if(r <= max){
		printf("OK");
	}else{
		printf("OVERFLOW");
	}
	return 0;
}
