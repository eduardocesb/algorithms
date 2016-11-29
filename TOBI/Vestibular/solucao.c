#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	char g[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%c", &g[i]);
	}
	int r = 0;
	char x[n];
	for(i=0;i<=n;i++){
		scanf("%c", &x[i]);
	}
	for(i=0;i<=n;i++){
		printf("%c",g[i]);
	}
	printf("\n");
	for(i=0;i<=n;i++){
		printf("%c",x[i]);
	}
	printf("%d", r);
	return 0;
}
