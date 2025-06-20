#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showMenu(int *option) {
  char buffer[100];

  printf("Selecione uma operação:\n");
  printf("1. Adição\n2. Subtração\n3. Multiplicação\n4. Divisão\n5. Sair\n");
  printf("Opção: ");
  if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    if (sscanf(buffer, "%d", option) != 1) {
      *option = 0;
    }
  } else {
    *option = 5;
  }
}

float getNumber() {
  char buffer[100];
  char *endptr;
  float number;

  while(1) {
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      buffer[strcspn(buffer, "\n")] = 0;

      if (buffer[0] == '\0') {
        printf("Erro: Nenhuma entrada inserida. Insira um número válido: ");
        continue;
      }

      number = strtof(buffer, &endptr);

      if (buffer != endptr && *endptr == '\0') {
        return number;
      }
    } else {
      printf("Fim da entrada. Saindo...\n");
      exit(0);
    }

    printf("Erro: Insira um número valido: ");
  }
}

int main() {
  int option = 0;
  float n1, n2, result;
  char operator;
  char doAgain = 's';
  
  do {
    printf("===============================\nCalculadora Simples\n===============================\n");
  
    while (option < 1 || option > 5) {
      showMenu(&option);

      if(option >= 1 && option <= 5) break;
      
      printf("\nOpção inválida! Por favor, selecione um número de 1 à 5.\n");
    }

    if (option == 5) {
      break;
    }
    
    printf("\nDigite o primeiro número: ");
    n1 = getNumber();

    printf("Digite o segundo número: ");
    n2 = getNumber();

    switch (option) {
      case 1: result = n1 + n2; operator = '+'; break;
      case 2: result = n1 - n2; operator = '-'; break;
      case 3: result = n1 * n2; operator = '*'; break;
      case 4:
        if (n2 == 0) {
          printf("Erro: Divisão por Zero não é permitida.\n");
          option = 0; 
          printf("\n");
          continue; 
        }
        result = n1 / n2; operator = '/'; break;
    }

    if (option == 2 && n2 < 0) {
      printf("Resultado: %g %c (%g) = %g\n", n1, operator, n2, result);
    } else {
      printf("Resultado: %g %c %g = %g\n", n1, operator, n2, result);
    }

    while (1) { 
      char answerBuffer[10];
      
      printf("\nDeseja realizar outra operação? (s/n): ");
      fgets(answerBuffer, sizeof(answerBuffer), stdin);
      sscanf(answerBuffer, " %c", &doAgain);

      if (doAgain == 's' || doAgain == 'S' || doAgain == 'n' || doAgain == 'N') break;

      printf("Resposta inválida, por favor digita 's' para sim ou 'n' para não\n");
    }

    if (doAgain == 's' || doAgain == 'S') {
      option = 0;
    }
    
  } while (doAgain == 's' || doAgain == 'S');

  printf("\nObrigado por usar a calculadora! Até a próxima. ^-^\n");

  return 0;
}
