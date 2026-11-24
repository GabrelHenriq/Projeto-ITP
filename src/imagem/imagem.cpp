#include "../paleta/paleta.h"
#include "imagem.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Imagem::Imagem(int largura, int altura){
    this->largura = largura;
    this->altura = altura;
    this->pixels = new Pixel*[this->largura];
    for (int i = 0; i < this->largura; i++){
        this->pixels[i] = new Pixel[this->altura];
    }
    for (int i = 0; i < this->largura; i++){
        for (int j = 0; j < this->altura; j++){
            this->pixels[i][j] = {0, 0, 0};
        }
    }
}

Imagem::Imagem(){
    this->largura = 0;
    this->altura = 0;
    this->pixels = nullptr;
}

Imagem::~Imagem(){
    delete[] pixels;
    this->pixels = nullptr;
}

int Imagem::obterLargura() const {
    return this->largura;
}

int Imagem::obterAltura() const {
    return this->altura;
}

void Imagem::definePixel(int i, int j, const Pixel& novosPixels){
    this->pixels[i][j] = {novosPixels.r, novosPixels.g, novosPixels.b};
}

Pixel Imagem::obterPixel(int i, int j) const{
    return pixels[i][j];
}

bool Imagem::lerPPM(const string& nomeArquivo){
    ifstream inputFile(nomeArquivo);
    string linha;
    string formato;
    int maximo;

    inputFile >> formato;

    if (formato != "P3"){
        return false;
    }

    inputFile >> this->largura >> this->altura;
    inputFile >> maximo;
    
    delete[] pixels;

    this->pixels = new Pixel*[this->largura];
    for (int i = 0; i < this->largura; i++){
        this->pixels[i] = new Pixel[this->altura];
    }

    Pixel novoPixel;

    for (int j = 0; j < this->altura; j++){
        for (int i = 0; i < this->largura; i++){
            inputFile >> novoPixel.r >> novoPixel.g >> novoPixel.b;
            definePixel(i, j, novoPixel);
        }
    }
    
    return true;
}

bool Imagem::salvarPPM(const string& nomeArquivo){
    ofstream outputFile;
    outputFile.open(nomeArquivo);
    outputFile << "P3" << endl;
    outputFile << this->altura << ' ' << this->largura << endl;
    outputFile << "255" << endl;
    for (int j = 0; j < this->altura; j++){
        for (int i = 0; i < this->largura; i++){
            outputFile << pixels[i][j].r << ' ' << pixels[i][j].g << ' ' << pixels[i][j].b << endl;
        }
    }
    outputFile.close();
    return true;
}