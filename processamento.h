#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <time.h>

#define DATAARCHIVEPATH			"./Arquivos/Dados/"
#define INDEXARCHIVEPATH		"./Arquivos/Index/"
#define POKEMONTABLE			"pokemon.csv"
#define ABILITYTABLE			"ability.csv"
#define TYPETABLE				"type.csv"
#define STATTABLE				"stat.csv"
#define POKEMONABILITYTABLE		"pokemon_ability.csv"
#define POKEMONTYPETABLE		"pokemon_type.csv"
#define POKEMONSTATTABLE		"pokemon_stat.csv"
#define LISTGOODPOKEMONAGAINST	"listOfGoodPokemonAgainst.csv"
#define ABILITY					1
#define POKEMON					2
#define STAT					3
#define TYPE					4
#define TYPEINDEX				5
#define DELIMITER				','

std::string devolve_time_contra(std::string arq1, std::string arq2, std::string index, std::string pokemons[]);
std::string getTypeById(std::string stringForSearch, std::fstream&);
int getId(std::string stringForSearch, int tabelaToSearch);
std::string verificaPokemonsContra(std::string pokemons[], std::string types[]);
int definelinha(int coluna);
int getListofRelationsById(std::string stringForSearch, int tabelaToSearch, std::string nameArchiveTemp);
std::string getNameById(std::string stringForSearch, int tabelaToSearch);