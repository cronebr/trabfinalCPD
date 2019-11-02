// trabsonfinal.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include "pokemon_class.h"
#include "type_class.h"
#include "algoritmos_de_ordenacao.h"
#include <locale.h>
#include <string.h>
#include <string>
#include <windows.h>

#define BANCO "pokebank.csv"
#define ORDENADO "ordenado.csv"

using namespace std;

void abre_le_arq();
void pokemonPreparator(string pokemonData);
vector<string> split(string s, char delimiter);

int main()
{

	setlocale(LC_ALL, "en_US.utf8");
	abre_le_arq();
    inicia_ordenacao(BANCO,ORDENADO,0);
	PokemonClass pokemon;//Objeto do tipo pokemon
	//dados_pokemon = ler_arquivo_de_dados();
	pokemon.insertName("linoone");
	cout << pokemon.getName();
}



void abre_le_arq()//abre e le o arquivo se der error estora o aviso
{
	fstream file;
	char line[500];
	try
	{
		file.open(BANCO);			//		Elimina a primeira linha, tira 1 verificação desnecessária
		file.getline(line, 1024);	//

		while (!file.eof()) {

			file.getline(line, 1024);
			pokemonPreparator(line);
		}
	}catch(string error)
	{
		cout << "Erro no arquivo" << "\n";
		cout << "Erro :"<< error << "\n";
	}

	file.close();
}

void pokemonPreparator(string pokemonData)// tratamento de 1 linha por vez
{
	char chars[] = "[]""'\"";

	for (unsigned int i = 0; i < strlen(chars); ++i)
	{
		// you need include <algorithm> to use general algorithms like std::remove()
		pokemonData.erase(std::remove(pokemonData.begin(), pokemonData.end(), chars[i]), pokemonData.end());
	}

	vector<string> teste = split(pokemonData, ',');
	cout << pokemonData << "\n";

}

vector<string> split(string s, char delimiter)//separa a string, em um array
{
	vector<std::string> tokens;
	string token;
	stringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
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
