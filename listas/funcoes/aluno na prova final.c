#include <stdio.h>

float min(float a, float b, float c)
{
    if (a <= b && a <= c)
    {
        return a;
    }
    else if (b <= a && b <= c)
    {
        return b;
    }
    else
    {
        return c;
    }
}
float calcNota(float nota1, float nota2, float nota3)
{
    float notaTotal = nota1 + nota2 + nota3;
    if (nota1 >= 3 && nota2 >= 3 && nota3 >= 3 && notaTotal / 3 < 5)
    {
        float media = notaTotal - min(nota1, nota2, nota3);
        return 15 - media;
    }
    else
    {
        return -1;
    }
}

int main()
{
    float nota1, nota2, nota3;
    scanf("%f %f %f", &nota1, &nota2, &nota3);
    float notaFinal = calcNota(nota1, nota2, nota3);
    if (notaFinal == -1)
    {
        printf("Nao faz prova final\n");
    }
    else
    {
        printf("Final\n%.1f\n", notaFinal);
    }
    return 0;
}