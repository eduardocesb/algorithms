#include <stdio.h>
int main(){
    int a;
    int b;
    int c;
    scanf("%d%d%d", &a,&b,&c);
    a = a/2;
    b = b/3;
    c = c/5;
    int r;
    r = 110;
    if(r > a){
    r=a;
    }
    if(r > b){
    r=b;
    }
    if(r > c){
    r=c;
    } 
    printf("%d", r);
    return 0;
}
