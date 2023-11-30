#include <stdio.h>

int main()
{
    int qtd, total;
    double vlr, produto, orcamento;

    // inicializa as variaveis de quantidade total e o somatorio do valor final.
    total = 0;
    orcamento = 0;

    while (1)
    {
        // ler a quantidade de itens.
        scanf("%d", &qtd);
        if (qtd == -1)
        {
            break;
        }

        // contador da quantidade total.
        total += qtd;

        // ler o valor unitário.
        scanf("%lf", &vlr);

        // calcula o valor de um único produto.
        produto = qtd * vlr;

        // contador do orcamento final
        orcamento += produto;
    }

    printf("%d %.2lf", total, orcamento);

    return 0;
}