#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nome[30];
    int votos;
} party;

party create()
{
    party new_party;
    new_party.votos = 0;

    scanf("%d %s[^\n]", &new_party.id, &new_party.nome);

    return new_party;
}

int auxiliar(int qtd_parties, party parties[qtd_parties], int id)
{
    for (int i = 0; i < qtd_parties; i++)
    {
        if (parties[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

int compute_votes(int num_votes, int votes[num_votes], int num_parties, party parties[num_parties], party *most_voted, party *second_most_voted)
{
    int valid_votes = 0;

    for (int i = 0; i < num_votes; i++)
    {
        int party_index = auxiliar(num_parties, parties, votes[i]);

        if (party_index != -1)
        {
            valid_votes++;
            parties[party_index].votos++;
        }
    }

    *most_voted = parties[0];
    *second_most_voted = parties[0];
    for (int i = 0; i < num_parties; i++)
    {
        if (parties[i].votos >= most_voted->votos)
        {
            *most_voted = parties[i];
        }
    }

    for (int i = 0; i < num_parties; i++)
    {
        if (parties[i].id != most_voted->id && parties[i].votos >= second_most_voted->votos)
        {
            *second_most_voted = parties[i];
        }
    }

    return valid_votes;
}

int main()
{
    int qtd_parties;
    scanf("%d", &qtd_parties);

    party parties[qtd_parties];
    for (int i = 0; i < qtd_parties; i++)
    {
        parties[i] = create();
    }

    int qtd_votos;
    scanf("%d", &qtd_votos);

    int votos[qtd_votos];
    for (int i = 0; i < qtd_votos; i++)
    {
        scanf("%d", &votos[i]);
    }

    party *most_voted = malloc(sizeof(party));
    party *second_most_voted = malloc(sizeof(party));

    int valid_votes = compute_votes(qtd_votos, votos, qtd_parties, parties, most_voted, second_most_voted);

    printf(
        "VENCEDOR: %s (%d votos = %.2f%%)\nVICE: %s (%d votos = %.2f%%)",
        most_voted->nome,
        most_voted->votos,
        (most_voted->votos / (valid_votes * 1.0)) * 100.0,
        second_most_voted->nome,
        second_most_voted->votos,
        (second_most_voted->votos / (valid_votes * 1.0)) * 100.0);

    return 0;
}
