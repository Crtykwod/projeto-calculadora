#include <stdio.h>

void showMenu(int *option) {
  int o;

  printf("===============================\nCalculadora Simples\n===============================\n");
  printf("Selecione uma operação:\n");
  printf("1. Adição\n2. Subtração\n3. Multiplicação\n4. Divisão\n5. Sair\n");
  printf("Opção: ");
  scanf("%d", &o);

  *option = o;
}

int main() {
  int option;
  float n1, n2, result;
  char operator;
  char doAgain;

  do {
    showMenu(&option);
    
    if (option > 5 || option < 0) {
      printf("Opção Inválida, por favor selecione uma opção de 1 à 4\n");
      return 0;
    }

    if (option == 5) {
      printf("Obrigado por usar a calculadora! Até a próxima");
      return 0;
    }
    
    printf("\nDigite o primeiro número: ");
    scanf("%f", &n1);
    printf("Digite o segundo número: ");
    scanf("%f", &n2);

    switch (option) {
      case 1:
        result = n1 + n2;
        operator = '+';
        break;
      
      case 2:
        result = n1 - n2;
        operator = '-';
        break;
      
      case 3:
        result = n1 * n2;
        operator = '*';
        break;
      
      case 4:
        if (n2 == 0) {
          printf("Erro: Divisão por Zero não é permitida.\n");
          break;
        }
        result = n1 / n2;
        operator = '/';
        break;
        
      default:
        printf("Algo deu errado, por favor tente novamente!");
        return 0;
    }

    if (option == 2 && n2 < 0) {
      printf("Resultado: %g %c (%g) = %g\n", n1, operator, n2, result);
    } else {
      printf("Resultado: %g %c %g = %g\n", n1, operator, n2, result);
    }
  
    printf("\nDeseja realizar outra operação? (s/n): ");
    scanf(" %c", &doAgain);

  } while (doAgain == 's' || doAgain == 'S');

  if (doAgain != 's' || doAgain != 'S') {
    printf("\nObrigado por usar a calculadora! Até a próxima. ^-^\n");
  }
}
