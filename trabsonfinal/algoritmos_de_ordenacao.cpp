#include "algoritmos_de_ordenacao.h"

void inicia_ordenacao(string arq1, string arq2,int coluna){
    copiaArquivo(arq1,arq2);
    heapsort(arq2,coluna);
}

void copiaArquivo(string arq1, string arq2){
    fstream file1,file2;
    char line[500];
    try
    {
        file1.open(arq1.c_str());
        file2.open(arq2.c_str(),fstream::out);

		while (!file1.eof()){
			file1.getline(line, 1024);
			file2 << line << "\n";
		}
	}catch(string error)
	{
		cout << "Erro no arquivo" << "\n";
		cout << "Erro :"<< error << "\n";
	}
	file1.close();
	file2.close();
}

void heapsort(string arq,int coluna){

}
