// trabsonfinal.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//***************************AREA DE LIBS*****************************
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <locale.h>
//****************AREA DE LIBS CRIADAS PELA GENTE*********************
#include "data_handler.h"
//********************************************************************

//************AREA DE CONSTANTES**************************************
#define BANCO "pokebank.csv"
//********************************************************************

//*************************AREA DE DECLARACAO DE FUNCOES**************


//********************************************************************

int main()
{
	setlocale(LC_ALL, "ja_JP.utf8"); //seta a linguagem para os caracteres especiais
	//****************************VARIAVEIS***************************

	Arquivos dataAux;//objeto auxiliar para criação de arquivos e lida com strings

	//********************FIM DAS VARIAVEIS***************************
	//*******************PROGRAMA*************************************
	dataAux.creationManager(BANCO);

    std::cout << "Hello World!\n";
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
