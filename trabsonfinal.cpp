#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <locale.h>
#include "algoritmos_de_ordenacao.h"

#define POKEMON "pokemon.csv"
#define COPIA "copia.csv"


int main()
{
    setlocale(LC_ALL,"en_US.utf8");
    inicia_ordenacao(POKEMON,COPIA,6);
    return 0;
}
