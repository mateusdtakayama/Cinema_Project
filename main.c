#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "biblioteca.h"

int main()
{

    //português
    setlocale(LC_ALL, "Portuguese");

    //variáveis importantes
    int tam = 7, num, fileira;
    char letra;

    //struct do sistema
    struct poltrona cinema[tam][tam];

    //coloca todas as poltronas como disponíveis
    zerador(tam, cinema);

    //tela de bemvindo
    bemvindo();

    //programa
    programa(tam, cinema, letra, fileira, num);

    return 0;
}

