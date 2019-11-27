#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#define DELIMITER ','
using namespace std;

void inicia_ordenacao(string arq1, string arq2,double coluna);
int copiaArquivo(string arq1, string arq2);
void heapsort(string arq,double coluna, double heap_size);
void build_heap(fstream&,double coluna,double heap_size_aux,double numero_de_linhas);
void heapify(fstream&, double elemento, double heap_size, double coluna, double numero_de_linhas);
