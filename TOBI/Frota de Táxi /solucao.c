#include <stdio.h>
int main(){
	float pa,pg,ra,rg;
	scanf("%f%f%f%f", &pa, &pg, &ra, &rg);
	if((pa/ra) < (pg/rg)){
		printf("A");
	}else{
		printf("G");
	}
	
	return 0;
}
