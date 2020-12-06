#include <stdio.h>
#include <stdlib.h>

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


void Print_Matriz()
{
  system("cls");
  for (int l = 0; l < 3; l++)
  {
    for (int c = 0; c < 3; c++)
    {
      printf("%d ", JOGO[l][c]);
    }
    printf("\n");
  }
}


int main() {

  int L, C, FIM, ERROR = 0;
  V[0] = 0; V[1] = 0;

  
  for (int l = 0; l < 3; l++){
    for (int c = 0; c < 3; c++){
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
      printf("Error\nEssa cordenada ja foi preenchida, escolha outra.\n");
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
      printf("Error\nEssa cordenada ja foi preenchida, escolha outra.\n");
      printf("Segundo jogador:\n");
      scanf("%d %d", &L, &C);
      if (JOGO[L-1][C-1] != 0){ ERROR = 1;}else{ERROR = 0;}
    }
    JOGO[L-1][C-1] = 2;

    Print_Matriz();


    Avaliacao();
    if (V[0] == 1) {break;}


  }
  if (V[1] == 1) {printf("O primeiro jogador ganhou!\n");}
  if (V[1] == 2) {printf("O Segundo jogador ganhou!\n");}
  if (V[1] == 0) {printf("Empate!\n");}

    return 0;
}
