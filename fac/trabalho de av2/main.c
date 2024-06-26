/* Suponha a existência de um vetor, inicialmente
  vazio (ou seja, uma variável quant terá o valor 0,
  inicialmente), com capacidade para armazenar
  até CAP números inteiros, onde CAP é uma
  constante.
  Pede-se o desenvolvimento de um programa
  que, através de um menu, permita ao usuário
  realizar as seguintes operações sobre o vetor
  (para cada operação, uma função deve ser
  implementada):
  1) Inserção de um novo número;
  2) Remoção de determinado valor;
  3) Remoção do elemento que encontra-se
  em uma dada posição;
  4) Alteração de um valor por outro;
  5) Busca de determinado número,
  retornando a sua posição (caso exista
  no vetor) ou o valor -1 se não for
  encontrado;
  6) Exibição de todos os elementos do vetor.
  A execução do sistema deve consistir na
  exibição do menu seguida da execução da
  operação escolhida, repetidas vezes, até que o
  usuário opte pela saída do programa.

  Observações:
  a. Os elementos do vetor devem estar
  ordenados crescentemente;
  b. Cada operação realizada deve garantir
  que o vetor se mantenha ordenado;
  c. Nenhum algoritmo de ordenação deve
  ser utilizado;
  d. São permitidos valores duplicados;
  e. Não são permitidas variáveis globais;
    */

#include <stdio.h>
// definição de constantes
#define CAP 10
// função secundária

int inserir(int vetor[], int *quant, int cap, int num);
int buscar(int vetor[], int quant, int num);
void mostrarVetor(int vetor[], int tam);

// função principal
void main() {

  // variaveis
  int vet[CAP], quantidade = 0;
  int valor, result, numero;
  // corpo
  do {
    printf("\n\tDigite um valor de 1 a 6:\n\t1)Inserção de um novo número.\n\t2)Remoção de determinado valor.\n\t3)Remoção do elemento que encontra-se em uma dada posição.\n\t4)Alteracao de um valor por outro.\n\t5)Busca de determinado numero.\n\t6)Exibição de todos os elementos do vetor.\n\t0)Sair do sistema. \n\n ");
    scanf("%d", &valor);
    switch (valor) {
    case 0:
      printf("\n\tSistema encerrado");

      break;
    case 1:
      printf("\n\tVoce escolheu o numero 1.\n");
      do {
        printf("\nValor a ser inserido: ");
        scanf("%d", &numero);

        result = inserir(vet, &quantidade, 10, numero);

        if (result == 1) {

          printf("\nO numero %d foi inserido no vetor\n", numero);
          mostrarVetor(vet, quantidade);
        } else {
          // inserção não realizada
          printf("\nO vetor atingiu seu limite\n");
        }
      } while (result == 1);

      break;
    case 2:
      printf("\n\tVoce escolheu o numero 2:\n Remova determinado valor do "
             "vetor\n\n ");
      break;
    case 3:
      printf("\n\tVoce escolheu o numero 3:\n Remova o numeor que se encontra "
             "em uma posicao\n\n ");
      break;
    case 4:
      printf("\n\tVoce escolheu o numero 4:\n Altere um valor por outro no "
             "vetor\n\n ");
      break;
    case 5:
      printf("\n\tVoce escolheu o numero 5:\n Busque um numero e retorne a "
             "posicao. Caso nao exista, retorne -1\n\n ");
      break;
    case 6:
      printf("\n\tVoce escolheu o numero 6:\n Exiba todos os elementos do "
             "vetor\n\n ");
      break;
    }
  } while (valor != 0);
}
// implementação da função -INSERIR
int inserir(int vetor[], int *quant, int cap, int num) {
  // variaveis
  int posicao, i;
  if (*quant < cap) {
    // buscando
    posicao = buscar(vetor, *quant, num);
    // movimentando para direita
    for (i = *quant - 1; i >=posicao; i--) {
      vetor[i + 1] = vetor[i];
    }
    // inserindo numero na posiçao
    vetor[posicao] = num;
    // atualiza a quantidade
    (*quant)++;

    return 1;

  } else {

    return 0;
  }
}

// implementação da função -BUSCAR

int buscar(int vetor[], int quant, int num) {
  // var
  int i;
  // percorrendo o vetor
  for (i = 0; i < quant; i++) {
    // verificando se 'numero' está na posição 'i' do vetor
    if (vetor[i] >= num) {
      return i;
    }
  }

  // num é maior do que todos os outos conteúdos do vetor
  return quant;
}
void mostrarVetor(int vet[], int tam) {

  printf("\n\tVetor: ");
  for (int i = 0; i < tam; i++) {

    printf("%d ", vet[i]);
  }
}
