#include <stdio.h>
int main(){
	int a,b,c,d,e;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	char r;
	if(b <= d){
		r = 'S';
	}else if(b <= e){
		r = 'S';
	}else if(c <= d){
		r = 'S';
	}else if(c <= e){
		r = 'S';
	}else{
	r = 'N';
	}
	printf("%c", r);
	
	return 0;
}
