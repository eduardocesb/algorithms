#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	char x;
	int i =0;
	int r;
	for (i =0; i<=n; i++){
		scanf("%c", &x);
		if(x == 'P'){
			r += 2;
		}else if(x == 'C'){
			r += 2;
		}else if(x == 'A'){
			r += 1;
		}else{
			r +=0;
		}
	}
	printf("%d", r);

	return 0;
}
