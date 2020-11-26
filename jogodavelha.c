#include <stdio.h>

int main() {

      //Definir o tabuleiro como vazio
      int GRID[3][3];
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          GRID[i][j] = 0;
        }
      }
      
      //Imprimir o tabuleiro
      for(int linha = 0 ; linha < 3 ; linha++){
          for(int coluna = 0 ; coluna < 3 ; coluna++){
              if(GRID[linha][coluna] == 0){
                  printf("0");
              }
              else{
                  if(GRID[linha][coluna] == 1){
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
