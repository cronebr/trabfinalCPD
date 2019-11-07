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
#define DATAARCHIVEPATH			"./Arquivos/Dados/"
#define INDEXARCHIVEPATH		"./Arquivos/Index/"
#define ABILITYTABLE			"ability.csv"
#define POKEMONTABLE			"pokemon.csv"
#define TYPETABLE				"type.csv"
#define STATTABLE				"stat.csv"
#define DELIMITER				','
#define ABILITIESDELIMITER		';'
#define ARRAYSIZE				200
#define LINESIZE				1024
#define COLUMNOFFSET			41
#define ID						"id"

#define ABILITIES				0
#define AGAINSTBUG				1
#define AGAINSTDARK				2
#define AGAINSTDRAGON			3
#define AGAINSTELECTRIC			4
#define AGAINSTFAIRY			5
#define AGAINSTFIGHT			6
#define AGAINSTFIRE				7
#define AGAINSTFLYING			8
#define AGAINSTGHOST			9
#define AGAINSTGRASS			10
#define AGAINSTGROUND			11
#define AGAINSTICE				12
#define AGAINSTNORMAL			13
#define AGAINSTPOISON			14
#define AGAINSTPSYCHIC			15
#define AGAINSTROCK				16
#define AGAINSTSTEEL			17
#define AGAINSTWATER			18
#define ATTACK					19
#define EGGSTEPS				20
#define HAPINNES				21
#define TOTALSTAT				22
#define CAPTURERATE				23
#define CLASSIFICATION			24
#define DEFENSE					25
#define EXPERIENCEGROWTH		26
#define HEIGHTM					27
#define HP						28
#define NAME					29
#define PERCENTAGEMALE			30
#define POKEDEXNUMBER			31
#define SPATTACK				32
#define SPDEFENSE				33
#define SPEED					34
#define TYPE1					35
#define TYPE2					36
#define WEIGHTKG				37
#define GENERATION				38
#define ISLEGENDARY				39
#define HASMEGA					40

//********************************************************************


int Arquivos::creationManager(std::string dataBaseName)
{
	
	switch (this->createFolders(DATAARCHIVEPATH, INDEXARCHIVEPATH))	//testa se a pasta existe se n�o existe ela cria e baseado no que aconteceu escolhe o que fazer
	{
		case -1:		//exce��o aconteceu
			std::cout << "Erro na cria��o\n";
			break;
		case 1:			//pasta foi criada
			std::cout << "Pastas foram criadas\n";
			this->createDataTables(dataBaseName);	//vai para a fun��o de cria��o das tabelas de dados
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
void Arquivos::createDataTables(std::string dataBaseName)
{
	this->createAbilityTable(dataBaseName);//****************PAREI AQUI, AJUSTAR PARA MANDAR OS DADOS DE UM ARQUIVO PRO OUTRO SEM MATRIZ
	//this->createPokemonTable(matriz);
	//1this->createTypeTable(matriz);
	//this->createStatTable(matriz);
	std::cout << "espere aqui";
}
//**************************************************************************************
//********************CRIA A TABELA DE HABILIDADES**************************************
void Arquivos::createAbilityTable(std::string dataBaseName)
{
	std::fstream file;//objeto file(ponteiro do arquivo), arquivo final
	std::string abilityAux;//string auxiliar para armazenar habilidades
	int index = 1;//id das habilidades
	bool firstTime = true;
	std::string stringAux;
	std::fstream databaseFonte;
	std::string abilities;
	char chars[] = "[]'\"\'";

	databaseFonte.open(std::string(dataBaseName));//abre o arquivo original para leitura
	file.open(std::string(DATAARCHIVEPATH).append(ABILITYTABLE), std::ios::in | std::ios::out | std::ios::app);//abre o arquivo de dados para escrita
	file << ID << DELIMITER << "abilities";	//coloca o cabecalho
	file.seekg(0, std::ios::beg);	//devolve o ponteiro para o inicio do arquivo
	std::getline(databaseFonte, abilities);//le o cabecalho do csv do arquivo fonte
	while (std::getline(databaseFonte, abilities,DELIMITER))	//pega a linha até o delimitador escolhido, se não tiver delimitador pega toda a linha
	{
		abilities = this->lineCleaner(abilities, chars);//abilities tem as habilidades do pokemon
		std::stringstream tokenStream(abilities);//transforma as habilidades em um stream para separacao
		while (std::getline(tokenStream, stringAux, ABILITIESDELIMITER))//itera entre todas as habilidades dentro do toKenStream
		{
			std::getline(file, abilityAux);//captura o cabecalho
			while (std::getline(file, abilityAux, DELIMITER) && firstTime)//itera nas habilidades que existem na tabela e diz se a atual ja foi inserida
			{
				std::getline(file, abilityAux);
				abilityAux.erase(std::remove(abilityAux.begin(), abilityAux.end(), '\n'), abilityAux.end());//apaga o \n da string
				if (abilityAux == stringAux) {
					firstTime = false;
				}
			}
			file.clear();//limpa as flags do objeto
			if (firstTime)//se é a primeira vez da habilidade insere ela na tabela
			{
				file << "\n" << index << DELIMITER << stringAux;
				index++;
			}
			firstTime = true;
			file.seekg(0, std::ios::beg);
		}
		std::getline(databaseFonte, abilities);//pega o resto da linha, para a insertTypeTable receber só as habilidades
	}
	databaseFonte.close();					//fecha o arquivo
	file.close();					//fecha o arquivo
}
//**************************************************************************************
//********************CRIA A TABELAS DE TIPOS*******************************************
void Arquivos::createTypeTable(std::vector<std::string> matriz)
{

	std::fstream file;//objeto file(ponteiro do arquivo)
	std::vector<std::string> abilititypeNames;
	std::vector<std::string> abilitityadvantages;
	file.open(std::string(DATAARCHIVEPATH).append(TYPETABLE), std::fstream::out);//abre o arquivo

	file << "id" << DELIMITER << "name" << DELIMITER << "against_bug" << DELIMITER << "against_dark" << DELIMITER << "against_dragon";
	file << DELIMITER << "against_electric" << DELIMITER << "against_fairy" << DELIMITER << "against_fight" << DELIMITER << "against_fire";
	file << DELIMITER << "against_flying" << DELIMITER << "against_ghost" << DELIMITER << "against_grass" << DELIMITER << "against_ground";
	file << DELIMITER << "against_ice" << DELIMITER << "against_normal" << DELIMITER << "against_poison" << DELIMITER << "against_psychic";
	file << DELIMITER << "against_rock" << DELIMITER << "against_steel" << DELIMITER << "against_water";				//coloca o cabe�alho

	for (int i = 35; i < matriz.size(); i += COLUMNOFFSET)
	{
		if (matriz[(long long)i+1] == "") {
			abilititypeNames.push_back(matriz[i] + DELIMITER + matriz[(long long)i - 34] + DELIMITER + matriz[(long long)i - 33] 
			+ DELIMITER + matriz[(long long)i - 32] + DELIMITER + matriz[(long long)i - 31] + DELIMITER + matriz[(long long)i - 30] 
			+ DELIMITER + matriz[(long long)i - 29] + DELIMITER + matriz[(long long)i - 28] + DELIMITER + matriz[(long long)i - 27] 
			+ DELIMITER + matriz[(long long)i - 26] + DELIMITER + matriz[(long long)i - 25] + DELIMITER + matriz[(long long)i - 24]
			+ DELIMITER + matriz[(long long)i - 23] + DELIMITER + matriz[(long long)i - 22] + DELIMITER + matriz[(long long)i - 21]
			+ DELIMITER + matriz[(long long)i - 20] + DELIMITER + matriz[(long long)i - 19] + DELIMITER + matriz[(long long)i - 18]
			+ DELIMITER + matriz[(long long)i - 17]);
		}
	}

	std::sort(abilititypeNames.begin(), abilititypeNames.end());											//elimina duplicatas
	abilititypeNames.erase(std::unique(abilititypeNames.begin(), abilititypeNames.end()), abilititypeNames.end());			//
	
	for (int i = 0; i < abilititypeNames.size(); i ++)
	{
		file << "\n" << i + 1 << DELIMITER << abilititypeNames[i];				//preenche o arquivo
	}

	file.close();					//fecha o arquivo
}
//**************************************************************************************
//********************CRIA AS TABELAS DE POKEMONS**************************************
void Arquivos::createPokemonTable(std::vector<std::string> matriz)
{

	std::fstream file;
	long index = 0, idSerial = 1;
	file.open(std::string(DATAARCHIVEPATH).append(POKEMONTABLE), std::fstream::out);//abre o arquivo
	file << "id" << DELIMITER << "name" << DELIMITER << "capture_rate" << DELIMITER;
	file << "classification" << DELIMITER << "pokedex_number" << DELIMITER << "weight_kg" << DELIMITER << "experience_growth";
	file << DELIMITER << "height_m" << DELIMITER << "percentage_male" << DELIMITER << "generation" << DELIMITER << "is_legendary";
	for (index = 40; index < matriz.size(); index += COLUMNOFFSET)
	{
		file << "\n" << idSerial << DELIMITER << matriz[((long long)index + NAME)] << DELIMITER << matriz[((long long)index + CAPTURERATE)] << DELIMITER;
		file << matriz[((long long)index + CLASSIFICATION)] << DELIMITER << matriz[((long long)index + POKEDEXNUMBER)] << DELIMITER << matriz[((long long)index + WEIGHTKG)] << DELIMITER << matriz[((long long)index + EXPERIENCEGROWTH)];
		file << DELIMITER << matriz[((long long)index + HEIGHTM)] << DELIMITER << matriz[((long long)index + PERCENTAGEMALE)] << DELIMITER << matriz[((long long)index + GENERATION)] << DELIMITER << matriz[((long long)index + ISLEGENDARY)];
		idSerial++;
	}

	file.close();					//fecha o arquivo
}
//**************************************************************************************
//********************CRIA A TABELA DE STATS********************************************
void Arquivos::createStatTable(std::vector<std::string> matriz)
{
		std::fstream file;
		long index = 0, idSerial = 1;
		file.open(std::string(DATAARCHIVEPATH).append(POKEMONTABLE), std::fstream::out);//abre o arquivo
		file << "id" << DELIMITER << "hp" << DELIMITER << "attack" << DELIMITER;
		file << "defense" << DELIMITER << "sp_attack" << DELIMITER << "sp_defense" << DELIMITER << "speed";
		file << DELIMITER << "base_egg_steps" << DELIMITER << "base_happiness" << DELIMITER << "base_total";
		for (index = 40; index < matriz.size(); index += COLUMNOFFSET)
		{
			file << "\n" << idSerial << DELIMITER << matriz[((long long)index + NAME)] << DELIMITER << matriz[((long long)index + CAPTURERATE)] << DELIMITER;
			file << matriz[((long long)index + CLASSIFICATION)] << DELIMITER << matriz[((long long)index + POKEDEXNUMBER)] << DELIMITER << matriz[((long long)index + WEIGHTKG)] << DELIMITER << matriz[((long long)index + EXPERIENCEGROWTH)];
			file << DELIMITER << matriz[((long long)index + HEIGHTM)] << DELIMITER << matriz[((long long)index + PERCENTAGEMALE)] << DELIMITER << matriz[((long long)index + GENERATION)] << DELIMITER << matriz[((long long)index + ISLEGENDARY)];
			idSerial++;
		}

		file.close();					//fecha o arquivo
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
	for (unsigned int i = 0; i < strlen(chars); ++i)//remove os char da fun��o
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
			resposta = 2;// existe pasta de dados mas n�o a de indices ent�o cria a de indices
		}
		else if (!fs::is_directory(dataFolder) && fs::is_directory(indexFolder))
		{
			fs::create_directories(dataFolder);
			resposta = 3;// existe pasta de index mas n�o a de dados ent�o cria a de dados
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