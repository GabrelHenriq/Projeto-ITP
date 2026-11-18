#include "paleta.h"
#include <string>

using namespace std;

Paleta::Paleta(int tamanho){
    this->tamanho = tamanho;
    this->quantidade = 0;
    this->cores = new Cor[this->tamanho];
}

Paleta::Paleta(const string& nomeArquivo){
    this->tamanho = 30;
    this->quantidade = 0;
    this->cores = new Cor[this->tamanho];
}

int Paleta::obterTamanho() const {
    return this->tamanho;
}

int Paleta::obterQuantidade() const {
    return this->quantidade;
}

void Paleta::adicionarCor(const Cor& cor){
    if (this->quantidade < this->tamanho){
        this->cores[this->quantidade] = {cor.r, cor.g, cor.b};
        this->quantidade++;
    }
}

Cor Paleta::obterCor(int indice){
    if (indice < 0 or indice >= this->quantidade){
        return {0, 0, 0};
    }
    return cores[indice];
}

// implemente aqui os métodos da classe Paleta, 
// conforme especificado no arquivo de cabeçalho paleta.h