#include <stdio.h>
#include <string.h>

struct Time
{
    char nome[100];
    int gols_marcados;
    int gols_sofridos;
};

void ordenarTimes(struct Time times[], int n)
{
    int i, j;
    struct Time temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (times[j].gols_marcados < times[j + 1].gols_marcados)
            {
                temp = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Time times[n];

    for (int i = 0; i < n; i++)
    {
        scanf(" %50[^\n]s", times[i].nome);
        scanf("%d", &times[i].gols_marcados);
        scanf("%d", &times[i].gols_sofridos);
    }
    ordenarTimes(times, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d - %s\n", i + 1, times[i].nome);
        printf("Gols marcados: %d\n", times[i].gols_marcados);
        printf("Gols sofridos: %d\n", times[i].gols_sofridos);
    }

    return 0;
}