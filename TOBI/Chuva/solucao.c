#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int v1[n][n];
	int v2[n][n];
	
	int i, j;
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
			scanf("%d", &v1[i][j]);
		}
	}
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
			scanf("%d", &v2[i][j]);
		}
	}
	int v3[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			v3[i][j] = (v1[i][j] + v2[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", v3[i][j]);
		}
		printf("\n");
	}
	return 0;
}
