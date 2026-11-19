#include "paleta.h"
#include "imagem.h"
#include <fstream>

Imagem::Imagem(int largura, int altura){
    this->largura = largura;
    this->altura = altura;
    this->pixels = new Pixel[this->largura][this->altura];
}

int obterLargura() const {
    return this->largura;
}

int obterAltura() const {
    return this->altura;
}

void definePixel(largura, altura, Pixel[largura, altura]){

}