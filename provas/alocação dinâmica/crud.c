/*CRUD - Com alocação dinâmica (Registros)

CRUD é uma das principais atividades que fazemos em qualquer sistema de informação. Como o nome já remete, essa expressão vem do ato de Criar, Ler, Atualizar e Deletar informações, essa expressão é bem comum no desenvolvimento WEB mas também em sistemas menores estaremos sempre fazendo uma parte deste trabalho.

Para fazer CRUD em C uma das principais partes é modelar os dados que estarão envolvidos nas operações. Nossos dados serão o clássico de uma Pessoa: nome (sem limite de caracteres), idade (um número inteiro), sexo (uma dentre três possibilidades M-masculino, F-feminino, N-nao informado).

​Modele um registro (struct) que possa ser usada para armazenar os dados no formato especificado.
O programa deve armazenar qualquer número de entradas recebido (use alocação dinâmica para um vetor da struct modelada).
Usando a struct e o vetor de structs, implemente as seguintes funções:

criar: uma função que recebe como parâmetro os valores a serem preenchidos nos campos do registro: nome, idade e sexo; a função retorna uma struct preenchida com os campos fornecidos.
inserir: uma função que recebe como parâmetro o vetor de structs, contendo todas as entradas até agora, e uma struct do formato especificado. A função deve inserir a struct recebida no fim do vetor.
deletar: uma função que recebe uma struct do formato projetado e um vetor com os elementos atualmente adicionados. A função deve buscar o elemento dentro do vetor e deletar este elemento. Um elemento só é considerado igual a outro quando todos os seus campos são iguais. Após deletar, a função deve atualizar o vetor de elementos para conter apenas elementos válidos (desloque todos os elementos depois do deletado uma posição para trás)​
imprimir: uma função que recebe um vetor de structs com o formato projetado e imprime todos os elementos válidos no vetor.​
O programa deve terminar quando executar a função 'imprimir'. A entrada é especificada no formato:

​i
julio melo
34
M
i
helliny frança
32
F
Rebecca Chambers
38
N
d
julio melo
34
M
p
No exemplo, 'i' denota a função "inserir" com os parâmetros que seguem, 'p' denota a função "imprimir" e d, deonta a função "deletar" com os parâmetros que seguem.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa
{
    char nome[100];
    int idade;
    char sexo;
};

// Função para criar uma pessoa
struct Pessoa criar()
{
    struct Pessoa pessoa;
    scanf(" %[^\n]", pessoa.nome);
    scanf("%d", &pessoa.idade);
    scanf(" %c", &pessoa.sexo);
    return pessoa;
}

// Função para inserir uma pessoa no vetor
void inserir(struct Pessoa **vetor, int *tamanho, struct Pessoa novaPessoa)
{
    (*tamanho)++;
    (*vetor) = (struct Pessoa *)realloc((*vetor), (*tamanho) * sizeof(struct Pessoa));
    (*vetor)[(*tamanho) - 1] = novaPessoa;
}
// Função de deletar pessoa no vetor
void deletar(struct Pessoa **vetor, int *tamanho, struct Pessoa pessoaParaDeletar)
{
    for (int i = 0; i < (*tamanho); i++)
    {
        if (strcmp((*vetor)[i].nome, pessoaParaDeletar.nome) == 0 &&
            (*vetor)[i].idade == pessoaParaDeletar.idade &&
            (*vetor)[i].sexo == pessoaParaDeletar.sexo)
        {
            for (int j = i; j < (*tamanho) - 1; j++)
            {
                (*vetor)[j] = (*vetor)[j + 1];
            }
            (*tamanho)--;
            (*vetor) = (struct Pessoa *)realloc((*vetor), (*tamanho) * sizeof(struct Pessoa));
            i--;
        }
    }
}

void imprimir(struct Pessoa *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%s,%d,%c\n", vetor[i].nome, vetor[i].idade, vetor[i].sexo);
    }
}

int main()
{
    struct Pessoa *pessoas = NULL;
    int tamanho = 0;
    char opcao;

    while (1)
    {
        scanf(" %c", &opcao);

        if (opcao == 'i')
        {
            struct Pessoa novaPessoa = criar();
            inserir(&pessoas, &tamanho, novaPessoa);
        }
        else if (opcao == 'd')
        {
            struct Pessoa pessoaParaDeletar = criar();
            deletar(&pessoas, &tamanho, pessoaParaDeletar);
        }
        else if (opcao == 'p')
        {
            imprimir(pessoas, tamanho);
            break;
        }
        else if (opcao == 's')
        {
            break;
        }
        else
        {
            printf("ERRO! Opção inexistente!.\n");
        }
    }

    free(pessoas);
    return 0;
}