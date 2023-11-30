#include <stdio.h>

int obterIntervalo(
    int n,
    int celulas[n],
    int distancia,
    int usuario,
    int *indiceEsquerdo,
    int *indiceDireito)
{
    int celulasNoIntervalo = 0;
    for (int i = 0; i < n; i++)
    {
        int noIntervalo =
            celulas[i] + distancia >= usuario &&
            celulas[i] - distancia <= usuario;

        if (
            noIntervalo && celulasNoIntervalo == 0)
        {
            *indiceEsquerdo = i;
            celulasNoIntervalo++;
        }
        else if (noIntervalo && celulasNoIntervalo > 0)
        {
            celulasNoIntervalo++;
        }
        else if (!noIntervalo && celulasNoIntervalo > 0)
        {
            *indiceDireito = (i - 1);
            break;
        }
    }

    return celulasNoIntervalo;
}

int main()
{
    int n, distancia, usuario;
    scanf("%d %d %d", &n, &distancia, &usuario);

    // O enunciado diz que sempre
    // vem na ordem crescente
    int celulas[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &celulas[i]);
    }

    int indiceEsquerdo;
    int indiceDireito;

    int celulasNoIntervalo = obterIntervalo(
        n,
        celulas,
        distancia,
        usuario,
        &indiceEsquerdo,
        &indiceDireito);

    if (celulasNoIntervalo == 0)
    {
        printf("USUARIO DESCONECTADO");
        return 0;
    }

    for (int i = indiceEsquerdo; i <= indiceDireito; i++)
    {
        printf("%d ", celulas[i]);
    }

    return 0;
}
