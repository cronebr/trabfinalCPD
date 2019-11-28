#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#define DELIMITER ','

void inicia_ordenacao(std::string arq1, std::string arq2,double coluna);
int copiaArquivo(std::string arq1, std::string arq2);
void heapsort(std::string arq,double coluna, double heap_size);
void build_heap(std::fstream&,double coluna,double heap_size_aux,double numero_de_linhas);
void heapify(std::fstream&, double elemento, double heap_size, double coluna, double numero_de_linhas);
