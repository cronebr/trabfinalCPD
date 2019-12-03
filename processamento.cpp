#include "processamento.h"

std::string devolve_time_contra(std::string arq1,std::string arq2,std::string index,std::string pokemons[]) {
	int ids[6],i;
	std::fstream file;
	std::string types[12],teste,pokemonsBonsContra;
	for (i = 0; i < 6;i++) {
		ids[i] = getId(pokemons[i],POKEMON);
		types[i*2] = getTypeById(std::to_string(ids[i]),file);
		teste = types[i*2];
		std::stringstream tokenStream(teste);
		std::getline(tokenStream, teste, DELIMITER);
		std::getline(tokenStream, teste, DELIMITER);
		std::getline(tokenStream, teste, DELIMITER);
		types[i*2] = teste;
		std::getline(tokenStream, teste, DELIMITER);
		std::getline(tokenStream, teste, DELIMITER);
		if (teste.compare(std::to_string(ids[i])) == 0) {
			std::getline(tokenStream, teste, DELIMITER);
			types[(i * 2) + 1] = teste;
		}
		else {
			types[(i * 2) + 1] = "0";
		}
	}
	pokemonsBonsContra = verificaPokemonsContra(pokemons, types);
	return pokemonsBonsContra;
}

std::string verificaPokemonsContra(std::string pokemons[], std::string types[]){
	std::string pokemonsBonsContra,bomContraType1[18],bomContraType2[18],linhalida1,linhalida2,valor1,valor2,aux,idTypeString,linhalida3,nome_pokemon_bom_contra;
	std::fstream file,file2;
	int i,j,linha1,linha2,linha1_aux,linha2_aux,types_bons_contra[18],numero_de_tipos_bons_contra,r,idType,numero_de_linhas;
	float bomContraTypeTotal[18],type1convert,type2convert;
	srand(time(NULL));
	for (i = 0; i < 6; i++) {
	}
	file.open(std::string(DATAARCHIVEPATH).append(TYPETABLE), std::fstream::out | std::ios::in | std::ios::app);
	for (i = 0; i < 6; i++) {
		linha1 = stoi(types[i*2]);
		linha2 = stoi(types[(i * 2)+1]);
		linha1_aux = linha1;
		linha2_aux = linha2;
		file.seekg(0, file.beg);
		std::getline(file, linhalida1);
		while (linha1_aux > 0) {
			std::getline(file, linhalida1);
			linha1_aux = linha1_aux - 1;
		}
		file.seekg(0, file.beg);
		std::getline(file, linhalida2);
		if (linha2 > 0) {
			while (linha2_aux > 0) {
				std::getline(file, linhalida2);
				linha2_aux = linha2_aux - 1;
			}
		}
		std::stringstream tokenStream1(linhalida1);
		std::getline(tokenStream1, valor1, DELIMITER);
		std::getline(tokenStream1, valor1, DELIMITER);
		std::stringstream tokenStream(linhalida2);
		std::getline(tokenStream, valor2, DELIMITER);
		std::getline(tokenStream, valor2, DELIMITER);
		for (j = 0; j < 18; j++) {
			if (linha2 == 0) {
				bomContraType2[j] = "-1";
			}else {
				std::getline(tokenStream, valor2, DELIMITER);
				bomContraType2[j] = valor2;
			}
			std::getline(tokenStream1, valor1, DELIMITER);
			bomContraType1[j] = valor1;
		}
		numero_de_tipos_bons_contra = 0;
		for (j = 0; j < 18; j++) {
			aux = bomContraType1[j];
			type1convert = std::strtof((aux).c_str(), 0);
			aux = bomContraType2[j];
			type2convert = std::strtof((aux).c_str(), 0);
			if (type2convert<0) {
				bomContraTypeTotal[j] = type1convert;
			}
			else {
				bomContraTypeTotal[j] = type1convert * type2convert;
			}
			if (bomContraTypeTotal[j] > 1) {
				types_bons_contra[numero_de_tipos_bons_contra] = j+1;
				numero_de_tipos_bons_contra = numero_de_tipos_bons_contra + 1;
			}
		}
		j = 0;
		while (numero_de_tipos_bons_contra > j) {
			j = j + 1;
		}
		r = rand() % numero_de_tipos_bons_contra;
		idType = definelinha(types_bons_contra[r]);
		idTypeString = std::to_string(idType);
		numero_de_linhas = getListofRelationsById(idTypeString,TYPE, std::string(DATAARCHIVEPATH).append(LISTGOODPOKEMONAGAINST));
		r = rand() % numero_de_linhas;
		file2.open(std::string(DATAARCHIVEPATH).append(LISTGOODPOKEMONAGAINST));
		while (r > 0) {
			std::getline(file2,linhalida3);
			r = r - 1;
		}
		nome_pokemon_bom_contra = getNameById(linhalida3, POKEMON);
		file2.close();
		remove(std::string(DATAARCHIVEPATH).append(LISTGOODPOKEMONAGAINST).c_str());
		pokemonsBonsContra = pokemonsBonsContra + nome_pokemon_bom_contra + "\r\n";
	}
	file.close();
	return pokemonsBonsContra;
}

int definelinha(int coluna){
	int linha = 0;
	switch (coluna) {
		case 0:
			linha = 0;
			break;
		case 1:
			linha = 3;
			break;
		case 2:
			linha = 14;
			break;
		case 3:
			linha = 12;
			break;
		case 4:
			linha = 5;
			break;
		case 5:
			linha = 6;
			break;
		case 6:
			linha = 7;
			break;
		case 7:
			linha = 1;
			break;
		case 8:
			linha = 18;
			break;
		case 9:
			linha = 15;
			break;
		case 10:
			linha = 11;
			break;
		case 11:
			linha = 9;
			break;
		case 12:
			linha = 16;
			break;
		case 13:
			linha = 10;
			break;
		case 14:
			linha = 4;
			break;
		case 15:
			linha = 8;
			break;
		case 16:
			linha = 13;
			break;
		case 17:
			linha = 17;
			break;
		case 18:
			linha = 2;
			break;
	}
	return linha;
}

std::string getTypeById(std::string stringForSearch, std::fstream& file)
{
	std::string resposta;
	std::string stringSearcher;
	bool isFoundIt = false;
	bool isTerminateIt = false;
	file.open(std::string(INDEXARCHIVEPATH).append(POKEMONTYPETABLE), std::fstream::out | std::ios::in | std::ios::app);
	std::getline(file, stringSearcher);//retira o cabecalho
	while (std::getline(file, stringSearcher) && !isTerminateIt)//faz o laco enquanto deve
	{
		resposta = stringSearcher;
		std::stringstream tokenStream(stringSearcher);//pega o stream
		while (std::getline(tokenStream, stringSearcher, DELIMITER) && !isFoundIt)// vai pegando as partes do stream ate a ,
		{
			std::getline(tokenStream, stringSearcher, DELIMITER);
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
	resposta = resposta.append(",");
	resposta = resposta.append(stringSearcher);
	file.close();
	return resposta;
}

int getId(std::string stringForSearch, int tabelaToSearch)// SE RETORNAR -1 O ID NÃO EXISTE, RETORNA O ID DA PRIMEIRA APARIÇÃO DA STRING PROCURADA NAO RECOMENDADA PARA BUSCA PARA STAT
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

int getListofRelationsById(std::string stringForSearch, int tabelaToSearch, std::string nameArchiveTemp)
{

	std::string resposta;
	std::fstream file;
	std::fstream filetemp;
	std::string stringSearcher;
	int numero_de_linhas = 0;


	filetemp.open(nameArchiveTemp, std::fstream::out | std::ios::in | std::ios::app);//abre o arquivo

	switch (tabelaToSearch)
	{
	case 1:
		file.open(std::string(INDEXARCHIVEPATH).append(POKEMONABILITYTABLE), std::fstream::out | std::ios::in | std::ios::app);//abre o arquivo
		break;
	case 3:
		file.open(std::string(INDEXARCHIVEPATH).append(POKEMONSTATTABLE), std::fstream::out | std::ios::in | std::ios::app);//abre o arquivo
		break;
	case 4:
		file.open(std::string(INDEXARCHIVEPATH).append(POKEMONTYPETABLE), std::fstream::out | std::ios::in | std::ios::app);//abre o arquivo
		break;
	}
	std::getline(file, stringSearcher);//retira o cabecalho
	while (std::getline(file, stringSearcher))//faz o laco enquanto deve
	{
		std::stringstream tokenStream(stringSearcher);//pega o stream
		std::getline(tokenStream, stringSearcher, DELIMITER);
		std::getline(tokenStream, stringSearcher, DELIMITER);
		resposta = stringSearcher;		//atribui a linha, que talvez seja a resposta 
		while (std::getline(tokenStream, stringSearcher, DELIMITER))// vai pegando as partes do stream ate a ,
		{
			if (stringForSearch == stringSearcher)// se encontrou o id, para de procurar
			{
				filetemp << resposta << '\n';
				numero_de_linhas = numero_de_linhas + 1;
			}
		}
	}
	file.close();
	filetemp.close();
	return numero_de_linhas;
}

std::string getNameById(std::string stringForSearch, int tabelaToSearch)
{
	std::string resposta;
	std::fstream file;
	std::string stringSearcher;
	bool isFoundIt = false;
	bool isTerminateIt = false;
	int aux = 5;

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
		std::stringstream tokenStream(stringSearcher);//pega o stream
		while (std::getline(tokenStream, stringSearcher, DELIMITER) && !isFoundIt)// vai pegando as partes do stream ate a ,
		{
			if (stringForSearch == stringSearcher)// se encontrou o id, para de procurar
			{
				isTerminateIt = true;
				isFoundIt = true;
				while (aux > 0) {
					std::getline(tokenStream, stringSearcher, DELIMITER);
					aux = aux - 1;
				}
				resposta = stringSearcher;
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