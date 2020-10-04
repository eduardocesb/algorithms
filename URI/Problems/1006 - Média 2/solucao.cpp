#include <cstdio>

int main(){
	double a,b,c;
	scanf("%lf %lf %lf", &a, &b, &c);
	double res = ((a * 2) + (b * 3) + (c * 5))/10;
	printf("MEDIA = %.1lf\n", res);
	return 0;
}
