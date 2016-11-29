#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	char g[n];
	int i;
	char x;
	scanf("%c",&x);
	x = ' ';
	for(i=0;i<=n;i++){
		scanf("%c",&x);
		g[i] = x;
	}
	
	int r = 0;
	char a[n];
	for(i=0;i<n;i++){
		scanf("%c",&x);
		a[i] = x;
		if(a[i] == g[i]){
			r += 1;
		}
	}
	
	printf("%d", r);
	return 0;
}
