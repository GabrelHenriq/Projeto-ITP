#pragma once
#include <string>

class Terreno {

private:

  int largura;
  int profundidade;
  float rugosidade;
  int** altitudes;

public:

  Terreno(int n);

  Terreno();

  ~Terreno();

  void diamond(); // mover esses para private depois

  void square();  // mover esses para private depois

  int obterAltitudePorCoord(int i, int j) const;

  int obterLargura() const;

  int obterProfundidade() const;

  bool salvarMatriz(const std::string& nomeArquivo);

  bool lerMatriz(const std::string& nomeArquivo);

};
