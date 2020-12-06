#include <stdio.h>
#include <stdlib.h>

int JOGO[5][5], V[2], G1 = 0, G2 = 0, G3 = 0;

void Avaliacao() {
  // Verificação Coluna
  for (int l = 0; l < 5; l++){
    for (int c = 0; c < 5; c++){
      if (JOGO[l][c] == 1){G1 ++;
      }else if(JOGO[l][c] == 2){G2++;}
    }
    if (G1 == 5){V[0] = 1;V[1] = 1;}
    if (G2 == 5){V[0] = 1;V[1] = 2;}
    G1 = 0; G2 = 0;
  }
  // Verificação Linha
  for (int c = 0; c < 5; c++){
    for (int l = 0; l < 5; l++){
      if (JOGO[l][c] == 1){G1 ++;
      }else if(JOGO[l][c] == 2){G2++;}
    }
    if (G1 == 5){V[0] = 1;V[1] = 1;}
    if (G2 == 5){V[0] = 1;V[1] = 2;}
    G1 = 0; G2 = 0;
  }
    // Verificação Diagonal
    for (int l = 0; l < 5; l++){
      for (int c = 0; c < 5; c++){
        if (c == l){
          if (JOGO[l][c] == 1){G1 ++;
          }else if(JOGO[l][c] == 2){G2++;}
        }
      }
    }
    if (G1 == 5){V[0] = 1;V[1] = 1;}
    if (G2 == 5){V[0] = 1;V[1] = 2;}
    G1 = 0; G2 = 0;
    // Verificação Diagonal inversa
    for (int l = 0; l < 5; l++){
      for (int c = 0; c < 5; c++){
        if ((c + l) == 4){
          if (JOGO[l][c] == 1){G1 ++;
          }else if(JOGO[l][c] == 2){G2++;}
        }
      }
    }
    if (G1 == 5){V[0] = 1;V[1] = 1;}
    if (G2 == 5){V[0] = 1;V[1] = 2;}
    G1 = 0; G2 = 0;
    // Verificação Empate
    for (int l = 0; l < 5; l++){
      for (int c = 0; c < 5; c++){
        if (JOGO[l][c] != 0){G3++;}
    }
  }
  if (G3 >= 25){V[0] = 1; V[1] = 0;}
  G3 = 0;
}


void Print_Matriz()
{
  printf("Tabuleiro:\n");
  for (int l = 0; l < 5; l++)
  {
    for (int c = 0; c < 5; c++)
    {
      printf("%d ", JOGO[l][c]);
    }
    printf("\n");
  }
  putchar('\n');
}


int main() {

  int L, C, FIM, ERROR = 0;
  V[0] = 0; V[1] = 0;


  for (int l = 0; l < 5; l++){
    for (int c = 0; c < 5; c++){
      JOGO[l][c] = 0;
    }
  }

  printf("Jogo da Velha!\n\n");

  while (1){

    printf("Primeiro jogador:\n");
    scanf("%d %d", &L, &C);
    if (JOGO[L-1][C-1] != 0)
    {
      ERROR = 1;
    }
    else
    {
      ERROR = 0;
    }

    while (ERROR == 1)
    {
      printf("Posicao Invalida!\nTente novamente!\n");
      printf("Primeiro jogador:\n");
      scanf("%d %d", &L, &C);
      if (JOGO[L-1][C-1] != 0)
      {
        ERROR = 1;
      }
      else
      {
        ERROR = 0;
      }
    }
    JOGO[L-1][C-1] = 1;

    Print_Matriz();

    Avaliacao();
    if (V[0] == 1){break;}

    printf("Segundo jogador:\n");
    scanf("%d %d", &L, &C);
    if (JOGO[L-1][C-1] != 0)
    {
      ERROR = 1;
    }
    else
    {
      ERROR = 0;
    }

    while (ERROR == 1)
    {
      printf("Posicao Invalida!\nTente novamente!\n");
      printf("Segundo jogador:\n");
      scanf("%d %d", &L, &C);
      if (JOGO[L-1][C-1] != 0){ ERROR = 1;}else{ERROR = 0;}
    }
    JOGO[L-1][C-1] = 2;

    Print_Matriz();


    Avaliacao();
    if (V[0] == 1) {break;}


  }
  if (V[1] == 1) {printf("Parabens! Primeiro jogador ganhou!\n");}
  if (V[1] == 2) {printf("Parabens! Segundo jogador ganhou!\n");}
  if (V[1] == 0) {printf("Empate!\n");}

    return 0;
}
