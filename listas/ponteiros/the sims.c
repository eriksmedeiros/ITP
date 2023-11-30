#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum acao
{
    aumentar,
    diminuir
};

enum status
{
    FOME,
    SEDE,
    BANHEIRO,
    SONO,
    TEDIO
};

const char status_messages[5][2][12] = {
    {"fome", "de fome"},
    {"sede", "de sede"},
    {"banheiro", "apertado..."},
    {"sono", "dormindo..."},
    {"tédio", "deprimido..."},
};

int aumentar_status(int *status, int qtd, int status_id, int pode_imprimir)
{
    *status += qtd;

    if (*status >= 100)
    {
        *status = 100;
    }
}