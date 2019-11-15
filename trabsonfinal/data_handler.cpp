//***************************AREA DE LIBS*****************************
#include <sstream>
#include <iostream>
#include <vector>
//#include <filesystem>
#include <algorithm>
#include <fstream>
//********************************************************************

//****************AREA DE LIBS CRIADAS PELA GENTE*********************
#include "data_handler.h"
//********************************************************************

//************AREA DE CONSTANTES**************************************
#define DATAARCHIVEPATH			"./Arquivos/Dados/"
#define INDEXARCHIVEPATH		"./Arquivos/Index/"
#define POKEMONTABLE			"pokemon.csv"
#define ABILITYTABLE			"ability.csv"
#define TYPETABLE				"type.csv"
#define STATTABLE				"stat.csv"
#define POKEMONABILITYTABLE		"pokemon_ability.csv"
#define POKEMONTYPETABLE		"pokemon_type.csv"
#define POKEMONSTATTABLE		"pokemon_stat.csv"
#define DELIMITER				','
#define ABILITIESDELIMITER		';'
#define COLUMNOFFSET			41
#define ABILITYHEADER			"id,abilities"
#define TYPEHEADER				"id,name,against_bug,against_dark,against_dragon,against_electric,against_fairy,against_fight,against_fire,against_flying,against_ghost,against_grass,against_ground,against_ice,against_normal,against_poison,against_psychic,against_rock,against_steel,against_water"
#define STATHEADER				"id,attack,egg_steps,happiness,total,defense,hp,sp_attack,sp_defense,speed"
#define POKEMONHEADER			"id,capture_rate,classification,experience_growth,height_m,name,percentage_male,pokedex_number,weight_kg,generation,is_legendary,has_mega"
#define POKEMONABILITYHEADER	"id,id_pokemon,id_ability"
#define POKEMONTYPEHEADER		"id,id_pokemon,id_type"
#define POKEMONSTATHEADER		"id,id_pokemon,id_stat"
#define ABILITY					1
#define POKEMON					2
#define STAT					3
#define TYPE					4

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
	this->createDataTables(dataBaseName);	//vai para a fun��o de cria��o das tabelas de dados
	this->createIndexTables(dataBaseName);
	/*switch (this->createFolders(DATAARCHIVEPATH, INDEXARCHIVEPATH))	//testa se a pasta existe se n�o existe ela cria e baseado no que aconteceu escolhe o que fazer
	{
		case -1:		//exce��o aconteceu
			std::cout << "Erro na cria��o\n";
			break;
		case 1:			//pasta foi criada
			std::cout << "Pastas foram criadas\n";
			//this->createDataTables(dataBaseName);	//vai para a fun��o de cria��o das tabelas de dados
			//this->createIndexTables(dataBaseName);	//vai para a fun��o de cria��o das tabelas de dados
			break;
		case 2:		//cria a pasta de index pq a de dados existia
			std::cout << "pasta de index criada\n";
			break;
		case 3:			//cria a pasta de dados pq a de index existia
			std::cout << "pasta de dados criada";
			break;
		default:	//pasta existe
			std::cout << "Pastas existiam\n";
			this->createIndexTables(dataBaseName);	//vai para a fun��o de cria��o das tabelas de dados
	}*/


	return 0;

}



//********************CRIA AS TABELAS DE ARQUIVOS**************************************
void Arquivos::createDataTables(std::string dataBaseName)
{
	this->createAbilityTable(dataBaseName);
	this->createPokemonTable(dataBaseName);
	this->createTypeTable(dataBaseName);
	this->createStatTable(dataBaseName);
	return;
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
	file << ABILITYHEADER;	//coloca o cabecalho
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
	return;
}
//**************************************************************************************
//********************CRIA A TABELAS DE TIPOS*******************************************
void Arquivos::createTypeTable(std::string dataBaseName)
{
	std::fstream file;//objeto file(ponteiro do arquivo)
	std::fstream databaseFonte;		//csv original
	std::fstream vectorSubs;		//arquivo auxiliar para nao usar ponteiros
	std::string typeFields;			//string para os campos do tipo no csv original
	std::fstream typessearched;			//string para os campos do tipo no csv original
	std::string typeFieldsvector;	// string pro arquivo auxiliar
	int index = 1;					//indice dos tipos
	bool keepIterating;				//bool pra parar de procurar os tipos
	int coluna;						//variavel para saber que atributo esta carregando

	file.open(std::string(DATAARCHIVEPATH).append(TYPETABLE), std::fstream::out);//abre o arquivo final
	typessearched.open(std::string(DATAARCHIVEPATH).append("guardatipos.bin"), std::ios::in | std::ios::out | std::ios::app);//abre o arquivo 
	databaseFonte.open(std::string(dataBaseName));	//abre o arquivo fonte
	file << TYPEHEADER;				//coloca o cabe�alho
	std::getline(databaseFonte, typeFields);
	while (std::getline(databaseFonte, typeFields))//itera no arquivo original 
	{
		vectorSubs.open(std::string(DATAARCHIVEPATH).append("helper.bin"), std::ios::in | std::ios::out | std::ios::app);//abre o arquivo auxiliar
		coluna = 0;
		keepIterating = true;
		typeFields.erase(std::remove(typeFields.begin(), typeFields.end(), '\n'), typeFields.end());//apaga o \n
		std::stringstream tokenStream(typeFields);//transforma as habilidades em um stream para separacao
		while (std::getline(tokenStream, typeFields, DELIMITER) && keepIterating)//procura as vantagens  dentro do toKenStream
		{
			switch (coluna)
			{
				case AGAINSTBUG:
				case AGAINSTDARK:
				case AGAINSTDRAGON:
				case AGAINSTELECTRIC:
				case AGAINSTFAIRY:
				case AGAINSTFIGHT:
				case AGAINSTFIRE:
				case AGAINSTFLYING:
				case AGAINSTGHOST:
				case AGAINSTGRASS:
				case AGAINSTGROUND:
				case AGAINSTICE:
				case AGAINSTNORMAL:
				case AGAINSTPOISON:
				case AGAINSTPSYCHIC:
				case AGAINSTROCK:
				case AGAINSTSTEEL:
				case AGAINSTWATER:
					vectorSubs << DELIMITER << typeFields;//guarda o valor no arquivo temporario
					break;
			}
			if (coluna== TYPE1) {
				keepIterating = false;
				getline(tokenStream, typeFieldsvector, DELIMITER);
				if (typeFieldsvector == "" && !(this->searchArchive(&typessearched, typeFields)))// se o segundo tipo for nulo guarda no arquivo
				{
					file << "\n" << index << DELIMITER << typeFields;
					vectorSubs.seekg(0, std::ios::beg);//volta pro inicio do arquivo auxiliar
					std::getline(vectorSubs, typeFieldsvector);
					file << typeFieldsvector;
					index++;
				}
			}
			coluna++;
		}
		vectorSubs.close();
		remove(std::string(DATAARCHIVEPATH).append("helper.bin").c_str());//deleta arquivo ajudante
	}
	//fecha o arquivo
	typessearched.close();					//fecha o arquivo
	remove(std::string(DATAARCHIVEPATH).append("guardatipos.bin").c_str());//deleta arquivo ajudante
	file.close();					//fecha o arquivo
	databaseFonte.close();					//fecha o arquivo
	return;
}
//*************************************************************************************
//******************PROCURA UMA STRING EM UM ARQUIVO DE UMA PALAVRA POR LINHA**********
bool Arquivos::searchArchive(std::fstream* file, std::string word)
{
	bool response = false;
	bool typeIsThere = false;
	std::string currentWord;
	while (std::getline(*file, currentWord) && !response)//procura as vantagens  dentro do toKenStream
	{
		currentWord.erase(std::remove(currentWord.begin(), currentWord.end(), '\n'), currentWord.end());//apaga o \n
		if (currentWord == word) 
		{
			response = true;
			typeIsThere = true;
		}
	}
	(*file).clear();
	if (!typeIsThere)
	{
		*file << word << "\n";
	}
	(*file).seekg(0, std::ios::beg);//volta pro inicio do arquivo auxiliar
	return response;
}
//*************************************************************************************
//********************CRIA AS TABELAS DE POKEMONS**************************************
void Arquivos::createPokemonTable(std::string dataBaseName)
{
	std::fstream pokemonTable;
	std::fstream databaseFonte;
	std::string pokemons;
	std::string stringAux;
	int index = 1;
	int coluna;

	databaseFonte.open(std::string(dataBaseName));//abre o arquivo original para leitura
	pokemonTable.open(std::string(DATAARCHIVEPATH).append(POKEMONTABLE), std::fstream::out);//abre o arquivo
	pokemonTable << POKEMONHEADER;
	std::getline(databaseFonte, pokemons);//le o cabecalho do csv do arquivo fonte
	while (std::getline(databaseFonte, pokemons))
	{
		coluna = 0;
		pokemons.erase(std::remove(pokemons.begin(), pokemons.end(), '\n'), pokemons.end());
		std::stringstream tokenStream(pokemons);//transforma as habilidades em um stream para separacao
		pokemonTable << "\n" << index;
		while (std::getline(tokenStream, stringAux, DELIMITER))//itera entre todas as habilidades dentro do toKenStream
		{
			switch (coluna)
			{
				case CAPTURERATE:
				case CLASSIFICATION:
				case EXPERIENCEGROWTH:
				case HEIGHTM:
				case NAME:
				case PERCENTAGEMALE:
				case POKEDEXNUMBER:
				case WEIGHTKG:
				case GENERATION:
				case ISLEGENDARY:
				case HASMEGA:
					pokemonTable << DELIMITER << stringAux;
					break;
			}
			coluna++;
		}
		index++;
	}
	databaseFonte.close();					//fecha o arquivo
	pokemonTable.close();					//fecha o arquivo
	return;
}
//**************************************************************************************
//********************CRIA A TABELA DE STATS********************************************
void Arquivos::createStatTable(std::string dataBaseName)
{
		std::fstream file;
		std::fstream databaseFonte;
		long index = 1, coluna = 0;
		std::string statLine;
		std::string stat;

		file.open(std::string(DATAARCHIVEPATH).append(STATTABLE), std::fstream::out);//abre o arquivo
		databaseFonte.open(std::string(dataBaseName));//abre o arquivo original para leitura
		file << STATHEADER;
		std::getline(databaseFonte, statLine);//le o cabecalho do csv do arquivo fonte
		while (std::getline(databaseFonte, statLine))
		{
			coluna = 0;
			statLine.erase(std::remove(statLine.begin(), statLine.end(), '\n'), statLine.end());
			std::stringstream tokenStream(statLine);//transforma as habilidades em um stream para separacao
			file << "\n" << index;
			while (std::getline(tokenStream, stat, DELIMITER))//itera entre todas as habilidades dentro do toKenStream
			{
				switch (coluna)
				{
				case ATTACK:
				case EGGSTEPS:
				case HAPINNES:
				case TOTALSTAT:
				case DEFENSE:
				case HP:
				case SPATTACK:
				case SPDEFENSE:
				case SPEED:
					file << DELIMITER << stat;
					break;
				}
				coluna++;
			}
			index++;
		}

		databaseFonte.close();					//fecha o arquivo
		file.close();					//fecha o arquivo
		std::cout << "espere aqui";
		return;
}	
//**************************************************************************************

//*****************SEPARA UMA STRING EM VETORES**************
std::vector<std::string> Arquivos::split(std::string s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::stringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
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


/*/********************CRIA A PASTA PARA AS TABELAS DE ARQUIVOS***************************
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
*///**************************************************************************************
//******************RECUPERA O ID DE UMA STRING DE UMA TABELA***************************
int Arquivos::getId(std::string stringForSearch, int tabelaToSearch)// SE RETORNAR -1 O ID NÃO EXISTE, RETORNA O ID DA PRIMEIRA APARIÇÃO DA STRING PROCURADA NAO RECOMENDADA PARA BUSCA PARA STAT
{
	std::fstream file;
	int resposta = 0;
	std::string stringSearcher;
	bool isFoundIt = false;

	switch (tabelaToSearch)
	{
		case ABILITY:
			file.open(std::string(DATAARCHIVEPATH).append(ABILITYTABLE), std::fstream::out | std::ios::in | std::ios::app);//abre o arquivo
			break;
		case POKEMON:
			file.open(std::string(DATAARCHIVEPATH).append(POKEMONTABLE), std::fstream::out | std::ios::in | std::ios::app);//abre o arquivo
			break;
		case STAT:
			file.open(std::string(DATAARCHIVEPATH).append(STATTABLE), std::fstream::out | std::ios::in | std::ios::app);//abre o arquivo
			break;
		case TYPE:
			file.open(std::string(DATAARCHIVEPATH).append(TYPETABLE), std::fstream::out | std::ios::in | std::ios::app);//abre o arquivo
			break;
	}
	std::getline(file, stringSearcher);
	while (std::getline(file, stringSearcher) && !isFoundIt)
	{
		resposta++;
		std::stringstream tokenStream(stringSearcher);
		while (std::getline(tokenStream, stringSearcher, DELIMITER))
		{
			stringSearcher.erase(std::remove(stringSearcher.begin(), stringSearcher.end(), '\n'), stringSearcher.end());//apaga o \n da string.erase(std::remove(abilityAux.begin(), abilityAux.end(), '\n'), abilityAux.end());//apaga o \n da string
			if (stringForSearch == stringSearcher) 
			{
				isFoundIt = true;
			}

		}
	}
	file.close();
	if (isFoundIt == false)
	{
		resposta = -1;//a palavra não existe na tabela
	}
	return resposta;
}
//**************************************************************************************
//******************BUSCA STRING NA TABELA BASEADO NO ID***********************
std::string Arquivos::getById(std::string stringForSearch, int tabelaToSearch)
{
	std::string resposta;
	std::fstream file;
	std::string stringSearcher;
	bool isFoundIt = false;
	bool isTerminateIt = false;

	switch (tabelaToSearch)
	{
	case 1:
		file.open(std::string(DATAARCHIVEPATH).append(ABILITYTABLE), std::fstream::out | std::ios::in | std::ios::app);//abre o arquivo
		break;
	case 2:
		file.open(std::string(DATAARCHIVEPATH).append(POKEMONTABLE), std::fstream::out | std::ios::in | std::ios::app);//abre o arquivo
		break;
	case 3:
		file.open(std::string(DATAARCHIVEPATH).append(STATTABLE), std::fstream::out | std::ios::in | std::ios::app);//abre o arquivo
		break;
	case 4:
		file.open(std::string(DATAARCHIVEPATH).append(TYPETABLE), std::fstream::out | std::ios::in | std::ios::app);//abre o arquivo
		break;
	}
	std::getline(file, stringSearcher);//retira o cabecalho
	while (std::getline(file, stringSearcher) && !isTerminateIt)//faz o laco enquanto deve
	{
		resposta = stringSearcher;		//atribui a linha, que talvez seja a resposta 
		std::stringstream tokenStream(stringSearcher);//pega o stream
		while (std::getline(tokenStream, stringSearcher, DELIMITER) && !isFoundIt)// vai pegando as partes do stream ate a ,
		{
			if (stringForSearch == stringSearcher)// se encontrou o id, para de procurar
			{
				isTerminateIt = true;
				isFoundIt = true;
			}
			else
			{
				isFoundIt = true;//senão verifica o proximo id
			}
		}
		isFoundIt = false;
	}
	file.close();


	return resposta;
}
//**************************************************************************************
//*****************CRIA AS TABELAS DE INDEX/RELACIONAMENTOS*****************************
void Arquivos::createIndexTables(std::string dataBaseName)//*****************************PAREI AQUI, TERMINAR OS RELACIONAMENTOS 
{
	this->createPokemon_AbilityTable(dataBaseName);//id,id_Pokemon,id_Ability
	this->createPokemon_TypeTable(dataBaseName);//id,id_Pokemon,id_Type
	this->createPokemon_StatTable(dataBaseName);////id,id_Pokemon,id_Stat
	return;
}
//**************************************************************************************
//****************CRIA O RELACIONAMENTO ENTRE POKEMONS E HABILIDADES********************
void Arquivos::createPokemon_AbilityTable(std::string dataBaseName)
{
	std::fstream fileDestiny;//tabela de destino
	std::fstream abilityTable;//tabela de habilidades
	std::fstream databaseFonte;
	char chars[] = "[]'\"\'";
	std::string stringLine;
	std::string partLine;
	int index = 1, pokemonId = 0;

	fileDestiny.open(std::string(INDEXARCHIVEPATH).append(POKEMONABILITYTABLE), std::fstream::out);//abre o arquivo
	databaseFonte.open(std::string(dataBaseName));//abre o arquivopara leitura
	abilityTable.open(std::string(dataBaseName));//abre o arquivo para leitura
	fileDestiny << POKEMONABILITYHEADER;
	std::getline(databaseFonte, stringLine);
	while (std::getline(databaseFonte, stringLine, DELIMITER))	//pega a linha até o delimitador escolhido, se não tiver delimitador pega toda a linha
	{
		pokemonId++;
		stringLine = this->lineCleaner(stringLine, chars);
		std::stringstream tokenStream(stringLine);
		while (std::getline(tokenStream, partLine, ABILITIESDELIMITER))
		{
			fileDestiny << "\n" << index << DELIMITER << pokemonId << DELIMITER << this->getId(partLine, ABILITY);//carrega no arquivo, os pokemons em sequencia com o id do tipo
			index++;
	 	}
		std::getline(databaseFonte, stringLine);//pega o resto da linha, para a insertTypeTable receber só as habilidades
	}

	abilityTable.close();
	fileDestiny.close();
	databaseFonte.close();
	return;
}
//**************************************************************************************
//***********CRIA O RELACIONAMENTO ENTRE POKEMONS E TIPOS*******************************
void Arquivos::createPokemon_TypeTable(std::string dataBaseName)
{
	std::fstream fileDestiny;
	std::fstream typeTable;
	std::fstream databaseFonte;
	std::string stringLine;
	int column = 0, pokemonId = 0, index = 1;
	bool isStop = false;

	fileDestiny.open(std::string(INDEXARCHIVEPATH).append(POKEMONTYPETABLE), std::fstream::out);//abre o arquivo
	databaseFonte.open(std::string(dataBaseName));//abre o arquivo original para leitura
	typeTable.open(std::string(dataBaseName));//abre o arquivo original para leitura
	fileDestiny << POKEMONTYPEHEADER;
	std::getline(databaseFonte, stringLine);
	while (std::getline(databaseFonte, stringLine))
	{
		column = 0;
		isStop = false;
		pokemonId++;
		std::stringstream tokenStream(stringLine);
		while (std::getline(tokenStream, stringLine, DELIMITER) && !isStop)
		{
			if (column==TYPE1) 
			{
				fileDestiny << "\n" << index << DELIMITER << pokemonId << DELIMITER << this->getId(stringLine,TYPE);//carrega no arquivo o tipo 1
				std::getline(tokenStream, stringLine, DELIMITER);//verifica se existe tipo 2
				if (stringLine != "") //se tiver carrega no arquivo senão segue o programa
				{
					index++;
					fileDestiny << "\n" << index << DELIMITER << pokemonId << DELIMITER << this->getId(stringLine, TYPE);
				}
				isStop = true;
			}
			else
			{
				column++;
			}
		}

		index++;
	}
	typeTable.close();
	fileDestiny.close();
	databaseFonte.close();
	return;
}
//**************************************************************************************
//*********************CRIA O RELACIONAMENTO ENTRE POKEMONS E STATS*********************
void Arquivos::createPokemon_StatTable(std::string dataBaseName)
{
	std::fstream fileDestiny;
	std::fstream databaseFont;
	std::string stringLine;
	int index = 1, idPokemon = 1, idStat = 1;

	fileDestiny.open(std::string(INDEXARCHIVEPATH).append(POKEMONSTATTABLE), std::fstream::out);//abre o arquivo
	databaseFont.open(std::string(dataBaseName));//abre o arquivo original para leitura
	fileDestiny << POKEMONSTATHEADER;
	std::getline(databaseFont, stringLine);
	while (std::getline(databaseFont, stringLine))//como durante a criação dos arquivos de stats e pokemons o programa segue a ordem do arquivo, os indices são i para i. Ou seja são iguais
	{
		fileDestiny << "\n" << index << DELIMITER << idPokemon << DELIMITER << idStat;
		index++;
		idPokemon++;
		idStat++;
	}
	fileDestiny.close();
	databaseFont.close();
	return;
}
//**************************************************************************************