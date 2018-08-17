#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int x[n];
	int i;
	int r;
	for(i=0;i<n;i++){
		scanf("%d", &x[i]);
		if((i == 0) || (x[i] < r)){
			r = x[i];
		}
	}
	
	printf("%d", r);
	return 0;
}
