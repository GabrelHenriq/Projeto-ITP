#include "paleta.h"
#include <string>
#include <fstream>

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
    ifstream inputFile(nomeArquivo);
    string linha;
    while (getline(inputFile, linha)){
        int cor_R = stoi(linha.substr(1, 2), nullptr, 16);
        int cor_G = stoi(linha.substr(3, 2), nullptr, 16);
        int cor_B = stoi(linha.substr(5, 2), nullptr, 16);
        adicionarCor(Cor{cor_R, cor_G, cor_B});
    };
    inputFile.close();

    
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
    } else {
        this->cores[this->quantidade] = {cor.r, cor.g, cor.b};
        this->quantidade++;
        this->tamanho++;
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