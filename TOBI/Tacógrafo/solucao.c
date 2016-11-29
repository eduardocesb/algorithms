#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int T, V, i, r;
	for(i=0;i<n;i++){
		scanf("%d%d", &T, &V);
		r += T*V;
	}
	printf("%d", r);
	return 0;
}
