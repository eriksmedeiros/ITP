#include <stdio.h>
 
int main() {
   int a, b;

   scanf("%d", &a);
   scanf("%d", &b);

   if(a%b==0){
    printf("Resultado: %d\n", a/b);
   }

    return 0;
}