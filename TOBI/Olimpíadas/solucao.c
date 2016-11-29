#include <stdio.h>
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int x;
	int i, j;
	int medalhas[n];
	int resp[n];
	for(i=0;i<n;i++){
		medalhas[i] = 0;
	}
	for(i=0;i<m;i++){
		for(j=0;j<3;j++){
			scanf("%d", &x);
			x = x -1;
			medalhas[x] = medalhas[x] + 1;
		}
	}
	int maior = 0;
	int smaior = 0;
	
	
	for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i=0){
					if(j=0 || maior<medalhas[j]){
						maior = medalhas[j];
						resp[i] = j+1;
					}
				}
			}
	}
	
	return 0;
}
