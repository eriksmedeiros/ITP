#include <stdio.h>
 
int main() {
   int T, L;

   scanf("%d", &T);

   if(0 <= T && T < 5){
    printf("Iniciante\n");
   }

   else if(5 <= T && T < 20){
        scanf("%d", &L);
        
        if(L == 0){
            printf("Iniciante\n");
        }
            
        else if(L == 1){
            printf("Intermediário\n");
        }   

   }


    else if(T >= 20){
        scanf("%d", &L);

        if(L == 0){
            printf("Intermediário\n");
        }

        else if(L == 1){
            printf("Avançado\n");
        }
    }   

    return 0;
}