#include <stdio.h>
#include <string.h>

struct Pessoa
{
    char nome[51];
    int idade;
    char sexo;
};

struct Pessoa criar(char nome[], int idade, char sexo)
{
    struct Pessoa pessoa;
    strncpy(pessoa.nome, nome, 50);
    pessoa.idade = idade;
    pessoa.sexo = sexo;
    return pessoa;
}

void imprimir(struct Pessoa pessoas[], int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        printf("%s,%d,%c\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
    }
}

void inserir(struct Pessoa pessoas[], struct Pessoa novaPessoa, int *quantidade)
{
    pessoas[*quantidade] = novaPessoa;
    (*quantidade)++;
}

void deletar(struct Pessoa pessoas[], struct Pessoa alvo, int *quantidade)
{
    for (int i = 0; i < *quantidade; i++)
    {
        if (strcmp(pessoas[i].nome, alvo.nome) == 0 && pessoas[i].idade == alvo.idade && pessoas[i].sexo == alvo.sexo)
        {
            for (int j = i; j < *quantidade - 1; j++)
            {
                pessoas[j] = pessoas[j + 1];
            }
            (*quantidade)--;
            i--;
        }
    }
}

int main()
{
    struct Pessoa pessoas[100];
    int quantidade = 0;

    char opcao;
    while (1)
    {
        scanf(" %c", &opcao);
        if (opcao == 'i')
        {
            char nome[51];
            int idade;
            char sexo;

            scanf(" %50[^\n]s", nome);
            while (getchar() != '\n')
                ;
            scanf("%d %c", &idade, &sexo);
            struct Pessoa novaPessoa = criar(nome, idade, sexo);
            inserir(pessoas, novaPessoa, &quantidade);
        }
        else if (opcao == 'd')
        {

            char nome[51];
            int idade;
            char sexo;

            scanf(" %50[^\n]s", nome);
            while (getchar() != '\n')
                ;
            scanf("%d %c", &idade, &sexo);
            struct Pessoa alvo = criar(nome, idade, sexo);
            deletar(pessoas, alvo, &quantidade);
        }
        else if (opcao == 'p')
        {
            imprimir(pessoas, quantidade);
            break;
        }
    }

    return 0;
}