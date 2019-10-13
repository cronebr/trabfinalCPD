// trabsonfinal.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "pokemon_class.h"
#define BANCO "pokebank.txt"
#include <locale.h>
#include <string.h>
#include <string>
using namespace std;
void abre_arq();
void le_arq(fstream* file);

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	abre_arq();
	PokemonClass pokemon;//Objeto do tipo pokemon
	//dados_pokemon = ler_arquivo_de_dados();
	pokemon.insertnome("linoone");
	cout << pokemon.getname();
}



void abre_arq()
{
	fstream file;
	try
	{
		file.open(BANCO, ios::in);
		le_arq(&file);
	}
	catch (string networkIOException)
	{
		printf("Erro ao abrir arquivo!\n");
	}
	file.close();
}

void le_arq(fstream* file)
{	
	string line, temp, palavra;
	while (*file >> temp)
	{
		getline(*file, line);
		cout << "\n" << line;
		//cout << "\n" << line;
		printf("\nDeu bom");
	}
}
// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar:
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
