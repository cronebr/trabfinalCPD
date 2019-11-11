#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Arquivos
{
	private:
		std::string lineCleaner(std::string lineData, char chars[]);//Limpa as linhas do csv dos caracteres indesejados
		//int createFolders(std::string dataFolder, std::string indexFolder);//testa as pasta e se não existirem as cria
		void createDataTables(std::string dataBaseName);	//função principal de criação das tabelas de dados
		void createTypeTable(std::string dataBaseName);	//função auxiliar de criação da tabelas de tipos
		void createAbilityTable(std::string dataBaseName);	//função auxiliar de criação da tabelas de habilidades
		void createPokemonTable(std::string dataBaseName);	//função auxiliar de criação da tabelas de pokemons
		void createStatTable(std::string dataBaseName);	//função auxiliar de criação da tabelas de stats
		bool searchArchive(std::fstream* file, std::string word);
	public:
		int creationManager(std::string dataBaseName);//manages the creation of the archives
		std::vector<std::string> split(std::string s, char delimiter);//separa uma string em vetores baseado em um delimitador
};