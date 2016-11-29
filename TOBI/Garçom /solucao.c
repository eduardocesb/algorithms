#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int l[n];
	int c[n];
	int r;
	int i;
	r =0;
	for(i=0;i<n;i++){
		scanf("%d%d",&l[i], &c[i]);
	}
	for(i=0;i<n;i++){
		if(l[i]>c[i]){
			r += c[i];
		}
	}
	printf("%d", r);
	return 0;
}
