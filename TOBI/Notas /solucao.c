#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	if(n == 0){
		printf("E");
	}else if(n>=1 && n <= 35){
		printf("D");
	}else if(n>=36 && n<=60){
		printf("C");
	}else if(n>=61 && n <=85){
		printf("B");
	}else{
		printf("A");
		}
	return 0;
}
