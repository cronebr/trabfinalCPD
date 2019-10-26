#include <iostream>
#include <string>
#include <vector>

class Arquivos
{
	private:
		std::string lineCleaner(std::string lineData, char chars[]);//Limpa as linhas do csv dos caracteres indesejados
		int createFolders(std::string dataFolder, std::string indexFolder);//testa as pasta e se n�o existirem as cria
		void createDataTables(std::vector<std::string> matriz);	//fun��o principal de cria��o das tabelas de dados
		void createTypeTable(std::vector<std::string> matriz);	//fun��o auxiliar de cria��o da tabelas de tipos
		void createAbilitieTables(std::vector<std::string> matriz);	//fun��o auxiliar de cria��o da tabelas de habilidades
		void createPokemonTable(std::vector<std::string> matriz);	//fun��o auxiliar de cria��o da tabelas de pokemons
		void createStatTable(std::vector<std::string> matriz);	//fun��o auxiliar de cria��o da tabelas de stats
		std::vector<std::string> matrixConstructor(std::string dataBaseName); // cria matriz com os dados
	public:
		int creationManager(std::string dataBaseName);//manages the creation of the archives
		std::vector<std::string> split(std::string s, char delimiter);//separa uma string em vetores baseado em um delimitador
};