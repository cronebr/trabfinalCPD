#include "algoritmos_de_ordenacao.h"

void inicia_ordenacao(string arq1, string arq2,double coluna){
    int numero_de_linhas_arquivo;
    numero_de_linhas_arquivo = copiaArquivo(arq1,arq2);
    heapsort(arq2,coluna,numero_de_linhas_arquivo);
}

int copiaArquivo(string arq1, string arq2){
    int numero_de_linhas = 0;
    fstream file1,file2;
    char line[500];
    string line2;
    int i = 0;
    try
    {
        file1.open(arq1.c_str());
        file2.open(arq2.c_str(),fstream::out);
        file1.getline(line,1024);

		while (!file1.eof()){
			file1.getline(line, 1024);
			numero_de_linhas = numero_de_linhas + 1;
			i = file1.gcount();
			file2 << line;
			while(i<199){
                file2 << '.';
                i = i + 1;
			}
			file2 << "\n";
		}
	}catch(string error)
	{
		cout << "Erro no arquivo" << "\n";
		cout << "Erro :"<< error << "\n";
	}
	file2.seekg(-3,file2.end);
	file2 << "\n";
	file1.close();
	file2.close();
	return numero_de_linhas;
}

void heapsort(string arq,double coluna, double heap_size){
    fstream file;
    string line0,line;
	double qtd_elementos,heap_size_aux,conta;
    heap_size_aux = heap_size;
    qtd_elementos = heap_size_aux-1;
    file.open(arq.c_str());
    build_heap(file,coluna,heap_size_aux);

    for(qtd_elementos;qtd_elementos>0;qtd_elementos--){
        file.seekg(0,file.beg);
        getline(file,line0);
		conta = 200 * qtd_elementos;
        file.seekg(conta,file.beg);
        getline(file,line);
        file.seekg(0,file.beg);
        file << line;
        file.seekg(conta,file.beg);
        file << line0;
        heap_size_aux = heap_size_aux - 1;
        heapify(file,0,heap_size_aux,coluna);
    }
    file.close();
}

void build_heap(fstream& file,double coluna,double heap_size_aux){
    double ultimo_pai;
    ultimo_pai = floor(heap_size_aux/2)-1;
    for (ultimo_pai;ultimo_pai>-1;ultimo_pai--){
        heapify(file,ultimo_pai,heap_size_aux,coluna);
    }
}

void heapify(fstream& file, double elemento, double heap_size, double coluna){
    double maior_elemento,filho_esquerdo,filho_direito,coluna_aux,conta1,conta2,conta3,conta4;
    string line,backup_M_E,backup_F_E,backup_F_D,str_maior_elemento,str_filho_esquerdo,str_filho_direito;
    maior_elemento = elemento;
    filho_esquerdo = floor(maior_elemento*2+1);
    filho_direito = floor(maior_elemento*2+2);
	conta1 = 200 * maior_elemento;
	conta2 = 200 * filho_esquerdo;
	conta3 = 200 * filho_direito;
    file.seekg(conta1,file.beg);
    getline(file,line);
    backup_M_E = line;
    file.seekg(conta2,file.beg);
    getline(file,line);
    backup_F_E = line;
    file.seekg(conta3,file.beg);
    getline(file,line);
    backup_F_D = line;
    stringstream tokenStreamM_E(backup_M_E);
    stringstream tokenStreamF_E(backup_F_E);
    stringstream tokenStreamF_D(backup_F_D);
    coluna_aux = coluna;
    while(coluna_aux>0){
        getline(tokenStreamM_E,str_maior_elemento,DELIMITER);
        getline(tokenStreamF_E,str_filho_esquerdo,DELIMITER);
        getline(tokenStreamF_D,str_filho_direito,DELIMITER);
        coluna_aux = coluna_aux - 1;
    }
    if(filho_esquerdo<heap_size && str_maior_elemento.compare(str_filho_esquerdo)<0){
        maior_elemento = filho_esquerdo;
	str_maior_elemento = str_filho_esquerdo;
    }
    if(filho_direito<heap_size && str_maior_elemento.compare(str_filho_direito)<0){
        maior_elemento = filho_direito;
    }
    if(maior_elemento!=elemento){
		conta4 = 200 * elemento;
		conta1 = 200 * maior_elemento;
        file.seekg(conta1,file.beg);
        getline(file,line);
        file.seekg(conta1,file.beg);
        file << backup_M_E;
        file.seekg(conta4,file.beg);
        file << line;
		heapify(file,maior_elemento,heap_size,coluna);
    }
}

