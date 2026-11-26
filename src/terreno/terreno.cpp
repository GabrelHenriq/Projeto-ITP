#include "terreno.h"
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

Terreno::Terreno(int n){
    if (n == 0){
        this->largura = 1;
        this->profundidade = 1;
    } 
    else {
        this->largura = (pow(2, n) + 1);
        this->profundidade = (pow(2, n) + 1);
    }
    this->altitudes = new int*[this->largura];
    for (int i = 0; i < this->largura; i++){
        this->altitudes[i] = new int[this->profundidade];
    }
    for (int i = 0; i < this->largura; i++){
        for (int j = 0; j < this->profundidade; j++){
            this->altitudes[i][j] = nullptr;
        }
    }
}

Terreno::Terreno(){
    this->largura = 0;
    this->profundidade = 0;
    this->altitudes = nullptr;
}

Terreno::~Terreno(){
    delete[] altitudes;
}

/* 
pega as quatro extremidades;
for(int i = 0; i <= n; i++){
    diamond();
    square();
}

*/

void diamond(){
    int d = 0;

    e1 = 0,0;
    e2 = 0,this->profundidade;
    e3 = this->largura,0;
    e4 = this->largura, this->profundidade;

    ponto novo = (this->largura/2),(this->profundidade/2)

    d++;
}

void square(){

}

int Terreno::obterAltitudePorCoord(int i, int j) const{
    return altitudes[i][j];
}

int Terreno::obterLargura() const {
    return this->largura;
}

int Terreno::obterProfundidade() const {
    return this->profundidade;
}

bool Terreno::salvarMatriz(const string& nomeArquivo){
    ofstream outputFile;
    outputFile.open(nomeArquivo);
    outputFile << this->largura << ' ' << this->profundidade << endl;
    for (int i = 0; i < this->largura; i++){
        for (int j = 0; j < this->profundidade; j++){
            outputFile << altitudes[i][j] << ' ';
        }
        outputFile << endl;
    }
    outputFile.close();
    return true;
}

bool Terreno::lerMatriz(const string& nomeArquivo){
    ifstream inputFile(nomeArquivo);

    inputFile >> this->largura >> this->profundidade;

    delete[] altitudes;

    this->altitudes = new int*[this->largura];
    for (int i = 0; i < this->largura; i++){
        this->altitudes[i] = new int[this->profundidade];
    }

    int novaAltitude;

    for (int i = 0; i < this->largura; i++){
        for (int j = 0; j < this->profundidade; j++){
            inputFile >> novaAltitude;
            this->altitudes[i][j] = novaAltitude;
        }
    }

    return true;
}

