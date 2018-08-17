#include <stdio.h>
int main(){
int a, b, c, d, e, f;
scanf("%d%d%d%d%d%d", &a,&b,&c,&d,&e,&f);
int fla;
int cor;
cor = a*3;
cor += b;
fla = d*3;
fla += e;
char r;
if(cor > fla){
	r = 'C';
}else{
	if(cor < fla){
		r = 'F';
	}else{
		if(c > f){
		r = 'C';
		}else{
			if(c < f){
				r = 'F';
			}else{
				r = '=';
			}	
		}
	}
}
printf("%c\n", r);

return 0;
}
