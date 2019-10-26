//***************************AREA DE LIBS*****************************
#include <sstream>
#include <iostream>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <fstream>
//********************************************************************

//****************AREA DE LIBS CRIADAS PELA GENTE*********************
#include "data_handler.h"
//********************************************************************

//************AREA DE CONSTANTES**************************************
#define DATAARCHIVEPATH "./Arquivos/Dados/"
#define INDEXARCHIVEPATH "./Arquivos/Index/"
#define DELIMITER		 ','
#define ABILITIESDELIMITER		 ';'
#define ARRAYSIZE		 500
#define LINESIZE		 1024
//********************************************************************


int Arquivos::creationManager(std::string dataBaseName)
{

	std::vector<std::string> matrix;
	
	switch (this->createFolders(DATAARCHIVEPATH, INDEXARCHIVEPATH))	//testa se a pasta existe se não existe ela cria e baseado no que aconteceu escolhe o que fazer
	{
		case -1:		//exceção aconteceu
			std::cout << "Erro na criação\n";
			break;
		case 1:			//pasta foi criada
			std::cout << "Pastas foram criadas\n";
			matrix = this->matrixConstructor(dataBaseName);//matriz com os pokemons
			this->createDataTables(matrix);	//vai para a função de criação das tabelas de dados
			break;
		case 2:		//cria a pasta de index pq a de dados existia
			std::cout << "pasta de index criada\n";
			break;
		case 3:			//cria a pasta de dados pq a de index existia
			std::cout << "pasta de dados criada";
			break;
		default:	//pasta existe
			std::cout << "Pastas existiam\n";
	}


	return 0;

}



//********************CRIA AS TABELAS DE ARQUIVOS**************************************
void Arquivos::createDataTables(std::vector<std::string> matriz)
{
	this->createAbilitieTables(matriz);
	std::cout << "espere aqui";
}
//**************************************************************************************
//********************CRIA A TABELA DE HABILIDADES**************************************
void Arquivos::createAbilitieTables(std::vector<std::string> matriz)
{
	std::fstream file;//objeto file(ponteiro do arquivo)
	std::vector<std::string> abilities;
	std::vector<std::string> tokensCarrier;
	file.open(std::string(DATAARCHIVEPATH).append("type.csv"), std::fstream::out);//abre o arquivo
	file << "index" << DELIMITER << "abilities";				//coloca o cabeçalho
	for (int i = 40; i < matriz.size(); i+= 40)
	{
		tokensCarrier = this->split(matriz[i], ABILITIESDELIMITER);									//divide os arrays em um vetor
		abilities.insert(std::end(abilities), std::begin(tokensCarrier), std::end(tokensCarrier));	//insere os tokens em um vetor
	}

	std::sort(abilities.begin(), abilities.end());											//elimina duplicatas
	abilities.erase(std::unique(abilities.begin(), abilities.end()), abilities.end());			//

	for (int i = 0; i < abilities.size(); i++)
	{
		file << "\n" << i+1 << DELIMITER << abilities[i];				//preenche o arquivo
	}

	file.close();					//fecha o arquivo
}
//**************************************************************************************
//********************CRIA A TABELAS DE TIPOS*******************************************
void Arquivos::createTypeTable(std::vector<std::string> matriz)
{
	std::cout << matriz[65];
	std::cout << "espere aqui";
}
//**************************************************************************************
//********************CRIA AS TABELAS DE POKEMONS**************************************
void Arquivos::createPokemonTable(std::vector<std::string> matriz)
{
	std::cout << matriz[65];
	std::cout << "espere aqui";
}
//**************************************************************************************
//********************CRIA A TABELA DE STATS********************************************
void Arquivos::createStatTable(std::vector<std::string> matriz)
{
	std::cout << matriz[65];
	std::cout << "espere aqui";
}
//**************************************************************************************

//*****************SEPARA UMA STRING EM VETORES**************
std::vector<std::string> Arquivos::split(std::string s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::stringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}
//**************************************************************

//********************LIMPA OS CARACTERES INDESEJADOS DO CSV***************************
std::string Arquivos::lineCleaner(std::string lineData, char chars[])// tratamento de 1 linha por vez
{
	for (unsigned int i = 0; i < strlen(chars); ++i)//remove os char da função
	{
		lineData.erase(std::remove(lineData.begin(), lineData.end(), chars[i]), lineData.end());
	}
	return lineData;
}
//**************************************************************************************


//********************CRIA A PASTA PARA AS TABELAS DE ARQUIVOS***************************
int Arquivos::createFolders(std::string dataFolder, std::string indexFolder)
{
	namespace fs = std::filesystem;
	int resposta = 0;// se as pastas ja existem
	try 
	{
		if (fs::is_directory(dataFolder) && fs::is_directory(indexFolder))
		{
	
		}
		else if (fs::is_directory(dataFolder) && !fs::is_directory(indexFolder))
		{
			fs::create_directories(indexFolder);
			resposta = 2;// existe pasta de dados mas não a de indices então cria a de indices
		}
		else if (!fs::is_directory(dataFolder) && fs::is_directory(indexFolder))
		{
			fs::create_directories(dataFolder);
			resposta = 3;// existe pasta de index mas não a de dados então cria a de dados
		}
		else
		{
			fs::create_directories(dataFolder);
			fs::create_directories(indexFolder);
			resposta = 1; // se as pastas foram criadas
		}
	}
	catch (std::string error ) 
	{
		resposta = -1;
	}
	return resposta;
}
//**************************************************************************************

//********************RETORNA O VETOR DE STRINGS COM A MATRIZ***************************
std::vector<std::string> Arquivos::matrixConstructor(std::string dataBaseName)// tratamento de 1 linha por vez
{

	std::fstream file;
	std::vector<std::string> resposta;
	std::vector<std::string> tokensCarrier;
	std::string lineCleaned;
	char line[ARRAYSIZE];
	char chars[] = "[]'\"\'";
	try
	{
		file.open(dataBaseName);			//				
		file.getline(line, LINESIZE);	//
		resposta = this->split(line, DELIMITER);
		while (!file.eof()) {

			file.getline(line, LINESIZE);
			lineCleaned = this->lineCleaner(line,chars);
			tokensCarrier = this->split(lineCleaned, DELIMITER);
			resposta.insert(std::end(resposta), std::begin(tokensCarrier), std::end(tokensCarrier));
		}
	}
	catch (std::string error)
	{
		std::cout << "Erro no arquivo" << "\n";
		std::cout << "Erro :" << error << "\n";
	}

	file.close();
	return resposta;
}
//**************************************************************************************