#include <stdio.h>
#include <string.h>
#define TAM 100

typedef struct
{
    char nomes[TAM][TAM];
    int tam;

} lista;

int checa_pessoa(lista t, char *str)
{
    for (int i = 0; i < t.tam; i++)
    {
        if (strcmp(str, t.nomes[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

lista insere_pessoa(lista t, char *str)
{
    if (checa_pessoa(t, str) == 0)
    {
        strcpy(t.nomes[t.tam], str);
        t.tam++;
    }
    return t;
}

lista remove_pessoa(lista t, char *str)
{
    lista aux;
    aux.tam = 0;

    if (checa_pessoa(t, str) == 1)
    {
        for (int i = 0; i < t.tam; i++)
        {
            if (strcmp(t.nomes[i], str) != 0)
            {
                strcpy(aux.nomes[aux.tam], t.nomes[i]);
                aux.tam++;
            }
        }

        t = aux;
    }

    return t;
}

void imprime_pessoas(lista t)
{
    printf("Atualmente trabalhando:\n");

    for (int i = 0; i < t.tam; i++)
    {
        printf("%s\n", t.nomes[i]);
    }
}

int main(void)
{
    lista equipe;
    char comando[TAM];
    int nComandos;
    char nome[TAM];

    equipe.tam = 0;

    scanf("%d", &nComandos);

    for (int i = 0; i < nComandos; i++)
    {

        scanf(" %s", comando);

        if (strcmp(comando, "INSERIR") == 0)
        {
            scanf(" %s", nome);

            equipe = insere_pessoa(equipe, nome);
        }
        else if (strcmp(comando, "REMOVER") == 0)
        {
            scanf(" %s", nome);

            equipe = remove_pessoa(equipe, nome);
        }
        else
        {
            imprime_pessoas(equipe);
            printf("\n");
        }
    }

    return 0;
}