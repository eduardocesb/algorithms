#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, d, topo = -1, apagados, i;
	char pilha[100001], num;
	while(scanf("%d%d", &n, &d) && n != 0 || d != 0){

		apagados = 0;

		for(i = 0, topo = -1; i < n; i++){
			scanf(" %c", &num);
			while(topo > -1 && apagados < d && num > pilha[topo]){
				topo--;
				apagados++;
			}
			if(topo+1 < n-d) pilha[++topo] = num;
		}
		pilha[++topo] = '\0';
		printf("%s\n", pilha);
	}
	return 0;
}