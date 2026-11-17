#include "paleta.h"
using namespace std;

Paleta::Paleta(int tamanho = 30){
    this->tamanho = tamanho;
    this->quantidade = 0;
    ...
}

Paleta::Paleta(const string& nomeArquivo){
    this->tamanho = 30;
    this->quantidade = 0;
}

int Paleta::obterTamanho(){
    return this->tamanho;
}

int Paleta::obterQuantidade(){
    return this->quantidade;
}

void Paleta::adicionarCor(const Cor& cor){
    ...
    quantidade++;
}

Cor Paleta::obterCor(int indice){

}

// implemente aqui os métodos da classe Paleta, 
// conforme especificado no arquivo de cabeçalho paleta.h