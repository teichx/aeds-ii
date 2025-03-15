#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int *dados;
  int inicio, fim, tamanho, capacidade;
} FilaCircular;

FilaCircular *newFilaCircular(int max)
{
  FilaCircular *fila = (FilaCircular *)malloc(sizeof(FilaCircular));
  if (!fila)
  {
    fprintf(stderr, "Erro: Falha na alocação de memória\n");
    exit(EXIT_FAILURE);
  }
  fila->dados = (int *)malloc(max * sizeof(int));
  if (!fila->dados)
  {
    fprintf(stderr, "Erro: Falha na alocação de memória\n");
    free(fila);
    exit(EXIT_FAILURE);
  }
  fila->capacidade = max;
  fila->inicio = 0;
  fila->fim = -1;
  fila->tamanho = 0;
  return fila;
}

void delFilaCircular(FilaCircular *fila)
{
  free(fila->dados);
  free(fila);
}

void enfileirar(FilaCircular *fila, int elem)
{
  if (fila->tamanho == fila->capacidade)
  {
    fprintf(stderr, "Erro: Overflow - Fila cheia\n");
    return;
  }
  fila->fim = (fila->fim + 1) % fila->capacidade;
  fila->dados[fila->fim] = elem;
  fila->tamanho++;
}

int desenfileirar(FilaCircular *fila)
{
  if (fila->tamanho == 0)
  {
    fprintf(stderr, "Erro: Underflow - Fila vazia\n");
    return -1;
  }
  int removido = fila->dados[fila->inicio];
  fila->inicio = (fila->inicio + 1) % fila->capacidade;
  fila->tamanho--;
  return removido;
}

void mostrar(FilaCircular *fila)
{
  if (fila->tamanho == 0)
  {
    printf("Fila vazia!\n");
    return;
  }
  for (int i = 0; i < fila->tamanho; i++)
  {
    printf("%d ", fila->dados[(fila->inicio + i) % fila->capacidade]);
  }
  printf("\n");
}

bool pesquisar(FilaCircular *fila, int elem)
{
  for (int i = 0; i < fila->tamanho; i++)
  {
    if (fila->dados[(fila->inicio + i) % fila->capacidade] == elem)
    {
      return true;
    }
  }
  return false;
}

int isVazia(FilaCircular *fila)
{
  return fila->tamanho == 0;
}

int isCheia(FilaCircular *fila)
{
  return fila->tamanho == fila->capacidade;
}

// void invertUsingStack(FilaCircular *fila)
// {
//   PilhaCircular stack = newPilhaCircular(fila->capacidade);
//   while (fila->tamanho > 0)
//   {
//     empilhar(&stack, desenfileirar(fila));
//   }
//   while (stack.n > 0)
//   {
//     enfileirar(fila, desempilhar(&stack));
//   }
// }

void mostrarRecursivo(FilaCircular *fila, int i)
{
  if (i == fila->tamanho)
  {
    printf("\n");
    return;
  }
  printf("%d ", fila->dados[(fila->inicio + i) % fila->capacidade]);
  mostrarRecursivo(fila, i + 1);
}

int main()
{
  FilaCircular *fila = newFilaCircular(5);
  printf(isVazia(fila) ? "Está vazia\n" : "Não está vazia\n");
  printf(isCheia(fila) ? "Esta cheia\n" : "Não está cheia\n");
  enfileirar(fila, 10);
  enfileirar(fila, 20);
  enfileirar(fila, 30);

  mostrarRecursivo(fila, 0);
  printf(isVazia(fila) ? "Está vazia\n" : "Não está vazia\n");
  printf(isCheia(fila) ? "Esta cheia\n" : "Não está cheia\n");

  enfileirar(fila, 40);
  enfileirar(fila, 50);
  printf(isVazia(fila) ? "Está vazia\n" : "Não está vazia\n");
  printf(isCheia(fila) ? "Esta cheia\n" : "Não está cheia\n");
  mostrarRecursivo(fila, 0);

  printf("Desenfileirado: %d\n", desenfileirar(fila));
  mostrarRecursivo(fila, 0);

  printf("Pesquisar 20: %s\n", pesquisar(fila, 20) ? "Encontrado" : "Não encontrado");
  printf("Pesquisar 50: %s\n", pesquisar(fila, 50) ? "Encontrado" : "Não encontrado");

  delFilaCircular(fila);
  return 0;
}