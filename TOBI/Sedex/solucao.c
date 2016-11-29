#include <stdio.h>
int main(){
	int b;
	scanf("%d", &b);
	int l, h,p;
	scanf("%d%d%d", &l, &h, &p);
	if((b <= l) && (b <= h) && (b <= p)){
		printf("S");
	}else{
		printf("N");
	}
	return 0;
}
