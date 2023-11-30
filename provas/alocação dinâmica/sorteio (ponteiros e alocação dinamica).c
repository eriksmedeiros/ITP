#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    char PARTICIPANTES[MAX][100];
    int n = 0;
    int sorteado[MAX] = {0};
    int i;
    char nome[100];

    while (1)
    {
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        if (strcmp(nome, "acabou") == 0)
        {
            break;
        }

        if (n < MAX)
        {
            strcpy(PARTICIPANTES[n], nome);
            n++;
        }
        else
        {
            printf("Máx. atingido!.\n");
            break;
        }
    }

    int semente;
    scanf("%d", &semente);
    srand((unsigned)semente);

    for (i = 0; i < n; i++)
    {
        int sorteio;
        do
        {
            sorteio = rand() % n;
        } while (sorteado[sorteio]);
        sorteado[sorteio] = 1;
        printf("%s\n", PARTICIPANTES[sorteio]);
    }
}