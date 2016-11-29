#include <stdio.h>
int main(){
	int f[10000001];
	int i, x, n, r=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d", &x);
		if(f[x] == 0){
			f[x] = 1;
			r += 1;
		}
	}
	printf("%d", r);
	return 0;
}
