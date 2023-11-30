#include <stdio.h>
#include <math.h>

int main()
{
    int valores[10];
    float contador_ma = 0, contador_mh = 0, contador_mg = 1;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &valores[i]);

        contador_ma = contador_ma + valores[i];
        contador_mh = contador_mh + pow(valores[i], -1);
        contador_mg = contador_mg * valores[i];
    }

    float erro_harm = ((10 / contador_mh) - (contador_ma / 10)) / (contador_ma / 10);
    float erro_geo = ((pow(contador_mg, 0.1)) - (contador_ma / 10)) / (contador_ma / 10);

    printf("Média aritmética é %.2f\n", contador_ma / 10.0);
    printf("Média harmônica é %.2f\n", 10.0 / contador_mh);
    printf("Média geométrica é %.2f\n", pow(contador_mg, 0.1));
    printf("Erro médio é %.2f %%", 100 * ((erro_harm + erro_geo) / 2.0));

    return 0;
}
