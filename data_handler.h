#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Arquivos
{
	private:
		std::string lineCleaner(std::string lineData, char chars[]);//Limpa as linhas do csv dos caracteres indesejados
		int createFolders(std::string dataFolder, std::string indexFolder);//testa as pasta e se não existirem as cria
		void createDataTables(std::string dataBaseName);	//função principal de criação das tabelas de dados
		void createIndexTables(std::string dataBaseName);	//função principal de criação das tabelas de index/relacionamentos
		void createTypeTable(std::string dataBaseName);	//função auxiliar de criação da tabelas de tipos
		void createAbilityTable(std::string dataBaseName);	//função auxiliar de criação da tabelas de habilidades
		void createPokemonTable(std::string dataBaseName);	//função auxiliar de criação da tabelas de pokemons
		void createStatTable(std::string dataBaseName);	//função auxiliar de criação da tabelas de stats
		bool searchArchive(std::fstream* file, std::string word);
		void createPokemon_AbilityTable(std::string dataBaseName);
		void createPokemon_TypeTable(std::string dataBaseName);
		void createPokemon_StatTable(std::string dataBaseName);
		void writePokemonsNameOnPokedexOrder(std::string namearchive);
		std::string mergeResults(std::string habilidade, std::string tipo, std::string ordem, std::string stat);
		std::vector<std::string> intersection(std::vector<std::string>& nums1, std::vector<std::string>& nums2);
		std::vector<std::string> chargeVector(std::vector<std::string>& vector1, std::string list);
		std::string Arquivos::getByNamebyStat(std::string tabelaToSearch);
	public:
		int getId(std::string stringForSearch, int tabelaToSearch);
		std::string searchFilters(std::string tipo1, std::string tipo2, std::string ordem, std::string stat);
		std::string getById(std::string stringForSearch, int tabelaToSearch);
		std::string getListofRelationsById(std::string stringForSearch, int tabelaToSearch , std::string nameArchiveTemp);
		std::string applyTypefilter(std::string ability);
		std::string applyabilityfilter(std::string type);
		std::string applyStatfilter(std::string stat);
		std::string applyOrdemfilter(std::string ordem);
		int creationManager(std::string dataBaseName);//manages the creation of the archives
		std::vector<std::string> split(std::string s, char delimiter);//separa uma string em vetores baseado em um delimitador
		std::string getNamefromTabelawithdot( std::string tabela);
};