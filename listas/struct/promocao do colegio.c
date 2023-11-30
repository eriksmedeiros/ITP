#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char nome[MAX];
    float nota;
} aluno;

typedef struct
{
    aluno pessoa[MAX];
    int tam_turma;
    float media;
} turma;

turma ler_turma()
{
    turma nova;
    char entrada[MAX];
    nova.tam_turma = 0;

    scanf("%s", entrada);

    while (strcmp(entrada, "*") != 0)
    {
        strcpy(nova.pessoa[nova.tam_turma].nome, entrada);
        scanf("%f", &nova.pessoa[nova.tam_turma].nota);
        nova.tam_turma++;

        scanf(" %[^\n]", entrada);
    }

    return nova;
}

float calcula_media(turma t)
{
    float media = 0;

    for (int i = 0; i < t.tam_turma; i++)
    {
        media += t.pessoa[i].nota;
    }

    return media / t.tam_turma;
}

aluno melhor_aluno(turma a, turma b)
{
    aluno vencedor = {.nota = 0};

    for (int i = 0; i < a.tam_turma; i++)
    {
        if (a.pessoa[i].nota > vencedor.nota)
        {
            vencedor = a.pessoa[i];
        }
    }

    for (int i = 0; i < b.tam_turma; i++)
    {
        if (b.pessoa[i].nota > vencedor.nota)
        {
            vencedor = b.pessoa[i];
        }
    }

    return vencedor;
}

int main()
{
    turma A, B;
    aluno melhor;

    A = ler_turma();
    B = ler_turma();

    A.media - calcula_media(A);
    B.media = calcula_media(B);

    if (A.media > 8.0 && B.media > 8.0)
        puts("Viagem para todos!");
    else if (A.media > 8.0)
        puts("Viagem para turma A");
    else if (B.media > 8.0)
        puts("Viagem para turma B");
    else
        puts("Nenhuma das turmas viaja...");

    melhor = melhor_aluno(A, B);

    if (melhor.nota > 8.0)
    {
        printf("%s ganhou viagem e ingresso no parque!\n", melhor.nome);
        printf("Nota: %.2f\n", melhor.nota);
    }
    else
        puts("Ninguem ganhou viagem e ingresso no parque...");

    return 0;
}