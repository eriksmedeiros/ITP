#include <stdio.h>

typedef struct
{
    char modelo[40];
    int memoria;
    float processador;
    float camera;
    float bateria;
} tabela;

tabela smartphone[20];

int cadastraSmartphone(int qnt_cadastrada, tabela phones[])
{
    scanf(" %[^\n]s", phones[qnt_cadastrada].modelo);
    scanf(" %d %f %f %f",
          &phones[qnt_cadastrada].memoria,
          &phones[qnt_cadastrada].processador,
          &phones[qnt_cadastrada].camera,
          &phones[qnt_cadastrada].bateria);

    return qnt_cadastrada + 1;
}

void imprimeSmartphone(tabela smartphone)
{
    printf("Modelo: %s\n", smartphone.modelo);
    printf("Memoria: %dGB\n", smartphone.memoria);
    printf("Processador: %.2fGhz\n", smartphone.processador);
    printf("Camera: %.2fMPixels\n", smartphone.camera);
    printf("Bateria: %.2fmA\n", smartphone.bateria);
    puts("");
}

int pesquisaSmarthpnes(int qnt_cadastrada, tabela phones[], tabela reqMin)
{
    int cont = 0;

    for (int i = 0; i < qnt_cadastrada; i++)
    {
        if ((phones[i].memoria >= reqMin.memoria) &&
            (phones[i].processador >= reqMin.processador) &&
            (phones[i].camera >= reqMin.camera) &&
            (phones[i].bateria >= reqMin.bateria))
        {
            imprimeSmartphone(phones[i]);
            cont++;
        }
    }
    return cont;
}

int main()
{
    int qnt_cadastrada = 0;
    char status;
    tabela reqMin;

    scanf(" %c", &status);

    do
    {
        qnt_cadastrada = cadastraSmartphone(qnt_cadastrada, smartphone);
        scanf(" %c", &status);
    } while (status == 's');

    scanf(" %d %f %f %f",
          &reqMin.memoria,
          &reqMin.processador,
          &reqMin.camera,
          &reqMin.bateria);

    int qnt_pesquisada = pesquisaSmarthpnes(qnt_cadastrada, smartphone, reqMin);
    printf("%d smartphones encontrados.", qnt_pesquisada);

    return 0;
}
