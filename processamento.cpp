#include "processamento.h"

void devolve_time_contra(std::string arq1,std::string arq2,std::string index,std::string pokemons[]) {
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
}

std::string verificaPokemonsContra(std::string pokemons[], std::string types[]){
	std::string pokemonsBonsContra,bomContraType1[18],bomContraType2[18],linha,valor1,valor2,aux;
	std::fstream file;
	int i,j,coluna1,coluna2,coluna1_aux,coluna2_aux,type1_aux,type2_aux,type1,type2,j_aux;
	float bomContraTypeTotal[18],type1convert,type2convert;
	for (i = 0; i < 6; i++) {
		std::cout << pokemons[i] << "," << types[i * 2] << "," << types[(i * 2) + 1] << "-";
	}
	file.open(std::string(DATAARCHIVEPATH).append(TYPETABLE), std::fstream::out | std::ios::in | std::ios::app);
	for (i = 0; i < 6; i++) {
		coluna1 = definecoluna(types[i*2]);
		coluna2 = definecoluna(types[(i * 2)+1]);
		std::cout << "\n" << coluna1 << " " << coluna2 << "\n";
		for (j = 0; j < 18; j++) {
			j_aux = j;
			coluna1_aux = coluna1;
			coluna2_aux = coluna2;
			file.seekg(0, file.beg);
			std::getline(file, linha);
			while (j_aux>-1) {
				std::getline(file, linha);
				j_aux = j_aux - 1;
			}
			std::stringstream tokenStream(linha);
			std::getline(tokenStream, valor1, DELIMITER);
			std::getline(tokenStream, valor1, DELIMITER);
			while(coluna1_aux>0){
				std::getline(tokenStream, valor1, DELIMITER);
				coluna1_aux = coluna1_aux - 1;
			}
			bomContraType1[j] = valor1;

			if (coluna2 == 0) {
				bomContraType2[j] = "-1";
			}else {
				j_aux = j;
				file.seekg(0, file.beg);
				std::getline(file, linha);
				while (j_aux > -1) {
					std::getline(file, linha);
					j_aux = j_aux - 1;
				}
				std::stringstream tokenStream1(linha);
				std::getline(tokenStream1, valor2, DELIMITER);
				std::getline(tokenStream1, valor2, DELIMITER);
				while (coluna2_aux > 0) {
					std::getline(tokenStream1, valor2, DELIMITER);
					coluna2_aux = coluna2_aux - 1;
				}
				bomContraType2[j] = valor2;
			}
		}
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
			std::cout << "\n" << type1convert << " " << type2convert << " " << bomContraTypeTotal[j] << "\n";
		}
	}
	file.close();
	return pokemonsBonsContra;
}

int definecoluna(std::string type){
	int typeconvert,coluna = 0;
	typeconvert = std::stoi(type);
	switch (typeconvert) {
		case 0:
			coluna = 0;
			break;
		case 1:
			coluna = 7;
			break;
		case 2:
			coluna = 18;
			break;
		case 3:
			coluna = 1;
			break;
		case 4:
			coluna = 14;
			break;
		case 5:
			coluna = 4;
			break;
		case 6:
			coluna = 5;
			break;
		case 7:
			coluna = 6;
			break;
		case 8:
			coluna = 15;
			break;
		case 9:
			coluna = 11;
			break;
		case 10:
			coluna = 13;
			break;
		case 11:
			coluna = 10;
			break;
		case 12:
			coluna = 3;
			break;
		case 13:
			coluna = 16;
			break;
		case 14:
			coluna = 2;
			break;
		case 15:
			coluna = 9;
			break;
		case 16:
			coluna = 12;
			break;
		case 17:
			coluna = 17;
			break;
		case 18:
			coluna = 8;
			break;
	}
	return coluna;
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