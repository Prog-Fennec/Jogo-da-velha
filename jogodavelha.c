#include <stdio.h>

int JOGO[3][3], V[2], G1 = 0, G2 = 0, G3 = 0;

void Avaliacao() {
  // Verificação Coluna
  for (int l = 0; l < 3; l++){
    for (int c = 0; c < 3; c++){
      if (JOGO[l][c] == 1){G1 ++;
      }else if(JOGO[l][c] == 2){G2++;}
    }
    if (G1 == 3){V[0] = 1;V[1] = 1;}
    if (G2 == 3){V[0] = 1;V[1] = 2;}
    G1 = 0; G2 = 0;
  }
  // Verificação Linha
  for (int c = 0; c < 3; c++){
    for (int l = 0; l < 3; l++){
      if (JOGO[l][c] == 1){G1 ++;
      }else if(JOGO[l][c] == 2){G2++;}
    }
    if (G1 == 3){V[0] = 1;V[1] = 1;}
    if (G2 == 3){V[0] = 1;V[1] = 2;}
    G1 = 0; G2 = 0;
  }
    // Verificação Diagonal
    for (int l = 0; l < 3; l++){
      for (int c = 0; c < 3; c++){
        if (c == l){
          if (JOGO[l][c] == 1){G1 ++;
          }else if(JOGO[l][c] == 2){G2++;}
        }
      }
    }
    if (G1 == 3){V[0] = 1;V[1] = 1;}
    if (G2 == 3){V[0] = 1;V[1] = 2;}
    G1 = 0; G2 = 0;
    // Verificação Diagonal inversa  
    for (int l = 0; l < 3; l++){
      for (int c = 0; c < 3; c++){
        if ((c + l) == 2){
          if (JOGO[l][c] == 1){G1 ++;
          }else if(JOGO[l][c] == 2){G2++;}
        }
      }
    }
    if (G1 == 3){V[0] = 1;V[1] = 1;}
    if (G2 == 3){V[0] = 1;V[1] = 2;}
    G1 = 0; G2 = 0; 
    // Verificação Empate 
    for (int l = 0; l < 3; l++){
      for (int c = 0; c < 3; c++){
        if (JOGO[l][c] != 0){G3++;}
    }
  }
  if (G3 >= 9){V[0] = 1; V[1] = 0;}
  G3 = 0;

}

int main() {

      //Definir o tabuleiro como vazio
      int JOGO[3][3];
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          JOGO[i][j] = 0;
        }
      }
      
      //Imprimir o tabuleiro
      for(int linha = 0 ; linha < 3 ; linha++){
          for(int coluna = 0 ; coluna < 3 ; coluna++){
              if(JOGP[linha][coluna] == 0){
                  printf("0");
              }
              else{
                  if(JOGO[linha][coluna] == 1){
                      printf("1");
                  }
                  else{
                      printf("2");
                  }
              }
          }
          putchar('\n');
      }
}      
