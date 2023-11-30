#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIMES 100
#define MAX_NOME 200

typedef struct
{
    char nome[MAX_NOME];
    int vitorias;
    int empates;
    int derrotas;
    int gols_feitos;
    int gols_sofridos;
} Time;

void leituraTimes(Time times[], int T)
{
    for (int i = 0; i < T; i++)
    {
        scanf("%[^;]; %d %d %d %d %d", times[i].nome, &times[i].vitorias, &times[i].empates, &times[i].derrotas, &times[i].gols_feitos, &times[i].gols_sofridos);
        getchar();
    }
}

int compararTimes(const void *a, const void *b)
{
    Time *timeA = (Time *)a;
    Time *timeB = (Time *)b;

    int pontosA = timeA->vitorias * 3 + timeA->empates;
    int pontosB = timeB->vitorias * 3 + timeB->empates;

    if (pontosA > pontosB)
        return -1;
    else if (pontosA < pontosB)
        return 1;
    else
    {
        if (timeA->vitorias > timeB->vitorias)
            return -1;
        else if (timeA->vitorias < timeB->vitorias)
            return 1;
        else
        {
            int saldoA = timeA->gols_feitos - timeA->gols_sofridos;
            int saldoB = timeB->gols_feitos - timeB->gols_sofridos;
            return saldoB - saldoA;
        }
    }
}

void imprimirTabela(Time times[], int T)
{
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");

    for (int i = 0; i < T; i++)
    {
        int pontos = times[i].vitorias * 3 + times[i].empates;
        int jogos = times[i].vitorias + times[i].empates + times[i].derrotas;
        int saldo_gols = times[i].gols_feitos - times[i].gols_sofridos;

        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n", times[i].nome, pontos, jogos, times[i].vitorias, times[i].empates, times[i].derrotas, times[i].gols_feitos, times[i].gols_sofridos, saldo_gols);
    }

    printf("\nTimes na zona da libertadores:\n");
    for (int i = 0; i < 6 && i < T; i++)
    {
        printf("%s\n", times[i].nome);
    }

    printf("\nTimes rebaixados:\n");
    for (int i = T - 1; i >= T - 4 && i >= 0; i--)
    {
        printf("%s\n", times[i].nome);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();

    Time times[MAX_TIMES];
    leituraTimes(times, T);

    qsort(times, T, sizeof(Time), compararTimes);

    imprimirTabela(times, T);

    return 0;
}