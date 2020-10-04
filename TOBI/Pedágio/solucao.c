#include <stdio.h>
int main(){
    int a;
    int b;
    scanf("%d%d", &a,&b);
    int c;
    int d;
    scanf("%d%d", &c, &d);
    int r;
    r = a*c;
    r += (a/b)*d;
    printf("%d", r);
    return 0 ;
}
