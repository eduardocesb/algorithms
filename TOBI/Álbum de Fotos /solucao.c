#include <stdio.h>
int main(){
	int x, y;
	int a, b;
	int c, d;
	scanf("%d%d", &x, &y);
	scanf("%d%d", &a, &b);
	scanf("%d%d", &c, &d);	
	char r;
	if((b+d<=y) && (a<=x) && (c<=x)){
		r = 'S';
	}else if((a+c<=x) && (b<=y) && (d<=y)){
		r = 'S';
	}else if((b+c<=y) && (a<=x) && (d<=x)){
		r = 'S';
	}else if((b+d<=x) && (a<=y) && (c<=y)){
		r = 'S';
	}else if((a+c<=y) && (b<=x) && (d<=x)){
		r = 'S';
	}else if((b+c<=x) && (a<=y) && (d<=y)){
		r = 'S';
	}else if((a+d<=x) && (b<=y) && (c<=y)){
		r = 'S';
	}else if((a+d<=y) && (b<=x) && (c<=x)){
		r = 'S';
	}else{
		r = 'N';
	}
	printf("%c", r);
	return 0;
}

