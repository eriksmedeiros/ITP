#include <stdio.h>
#include <string.h>

const char S[] =
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
     'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};

int indicePalavra(char palavras)
{
    for (int i = 0; i < 40; i++)
    {
        if (palavras == S[i])
        {
            return i;
        }
    }

    return -1;
}

void
