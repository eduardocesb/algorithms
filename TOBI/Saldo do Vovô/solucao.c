#include <stdio.h>
int main(){
	int n, saldo;
	scanf("%d%d", &n, &saldo);
	int min;
	min = saldo;
	int i;
	int x;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		saldo = saldo + x;
		if(saldo < min){
			min = saldo;
		}
	}
	printf("%d",min);
	return 0;
}
