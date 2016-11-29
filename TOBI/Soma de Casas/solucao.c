#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int i;
	int c[n];
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	int k;
	scanf("%d", &k);
	int j;
	for(i=0;i<(n-1);i++){
		for(j=n-1;j>i;j--){
			if(c[j]+c[i] == k){
				printf("%d %d",c[i], c[j]);
			}
		}
	
	}

	return 0;
}
