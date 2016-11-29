#include<stdio.h>
int main(){
   int teste=0; 
   int rodadas=1; 
   int aldo, beto; 
   int a, b;
   int i; 

   scanf("%d", &rodadas);
   while(rodadas) {
      printf("Teste %d\n", ++teste);
		aldo=0; beto=0;
      for(i=0;i<rodadas;i++) {
         scanf("%d %d", &a, &b);
         aldo+=a;
         beto+=b;
      }
      if(aldo>beto) printf("Aldo\n\n");
      else printf("Beto\n\n");
      scanf("%d", &rodadas);
   }

   return 0;
}
