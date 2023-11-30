#include <stdio.h>
#include <string.h>

void busca(char *email, int *inicio, int *fim)
{
    *inicio = -1;
    *fim = -1;
    int i = 0;

    while (email[i] != '\0')
    {
        if (email[i] == '@' && *inicio == -1)
        {
            *inicio = i;
        }
        else if (email[i] == '.' && *inicio != -1)
        {
            *fim = i;
            break;
        }
        i++;
    }
}

int main()
{
    char email[500];
    scanf("%s", email);

    int inicio, fim;

    while (strcmp(email, "FIM") != 0)
    {

        busca(email, &inicio, &fim);

        if (inicio != -1 && fim != 1)
        {

            for (int i = inicio + 1; i < fim; i++)
            {
                printf("%c", email[i]);
            }
            printf("\n");
        }

        scanf("%s", email);
    }

    return 0;
}
