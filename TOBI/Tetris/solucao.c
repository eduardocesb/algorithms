#include <stdio.h>
#include <string.h>

int main(){
	int n;
	scanf("%d",&n);
	int notas[12];
	int x,y;
	int aux;
	char auxn[16];
	int z=1;
	while (n != 0){
		char nome[n][16];
		int matrix[n];
		int i,j;
		for(i=0;i<n;i++){
			matrix[i] = 0;
			scanf("%s", nome[i]);
			for(j=0;j<12;j++){
				scanf("%d",&notas[j]);
			}
			for(x=11;x>=0;x--){
				for(y=0;y<x;y++){
					if(notas[x]<notas[y]){
						aux = notas[x];
						notas[x] = notas[y];
						notas[y] = aux;
					}
				}
			}
			for(x=1;x<11;x++){
				matrix[i] = notas[x] + matrix[i];
			}		
		}
		for(x=n-1;x>=0;x--){
			for(y=0;y<x;y++){
				if(matrix[x]>matrix[y]){
					aux = matrix[x];
					matrix[x] = matrix[y];
					matrix[y] = aux;
					
					strncpy(auxn, nome[x],16);
					strncpy(nome[x], nome[y],16);
					strncpy(nome[y], auxn,16);
				}else if(matrix[x] == matrix[y]){
					
				}
			}
		}
		printf("Teste %d\n", z);
		printf("\n");
		for(x=0;x<n;x++){
			printf("%d %d %s\n",(x+1), matrix[x], nome[x]);
		}
		z += 1;
		scanf("%d", &n);
	}
	return 0;
}
