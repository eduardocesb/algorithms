#include <stdio.h>
int main(){
	int vi, q;
	scanf("%d%d", &vi, &q);
	int i,x;
	for(i=0;i<q;i++){
		scanf("%d", &x);
		vi += x;
		if(vi > 100){
			vi = 100;
		}else if(vi < 0){
			vi = 0;
		}
	}
	printf("%d", vi);
	return 0;
}
