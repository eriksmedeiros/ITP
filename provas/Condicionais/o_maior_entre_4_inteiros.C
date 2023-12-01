#include <stdio.h>
 
int main() {
    int n1, n2, n3, n4;

    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    scanf("%d", &n4);

    if(n1 >= n2 && n1 >= n3 && n1 >= n4){
        printf("Maior: %d\n", n1);
    }

    else if(n2 >= n1 && n2 >= n3 && n2 >= n4){
        printf("Maior: %d\n", n2);

    }

    else if(n3 >= n1 && n3 >= n2 && n3 >= n4){
        printf("Maior: %d\n", n3);
    }

    else if(n4 >= n1 && n4 >= n3 && n4 >= n2){
        printf("Maior: %d\n", n4);
    }

    return 0;
}