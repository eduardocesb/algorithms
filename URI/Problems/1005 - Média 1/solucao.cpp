#include <cstdio>

int main(){
	double a,b;
	scanf("%lf %lf", &a, &b);
	double res = ((a * 3.5) + (b * 7.5))/11;
	printf("MEDIA = %.5lf\n", res);
	return 0;
}
