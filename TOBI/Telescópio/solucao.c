#include <stdio.h>
int main(){
	int n ,m;
	scanf("%d%d", &m, &n);
	int i, r, x;
	for(i=0;i<n;i++){
		scanf("%d", &x);
		if(x*m >= 40000000){
			r += 1;
		}
	}
	printf("%d", r);
	return 0;
}
