#include <stdio.h>
int main(){
	int x;
	int y;
	scanf("%d%d", &x, &y);
	if((x >= 0 && x <= 432) && (y >= 0 && y <= 468)){
		printf("dentro");
	}else{
		printf("fora");
	}
	return 0;
}
