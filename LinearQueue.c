#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int *dados;
  int tamanho, capacidade;
} FilaLinear;

FilaLinear *newFilaLinear(int max)
{
  FilaLinear *fila = (FilaLinear *)malloc(sizeof(FilaLinear));
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
  fila->tamanho = 0;
  return fila;
}

void delFilaLinear(FilaLinear *fila)
{
  free(fila->dados);
  free(fila);
}

void enfileirar(FilaLinear *fila, int elem)
{
  if (fila->tamanho == fila->capacidade)
  {
    fprintf(stderr, "Erro: Overflow - Fila cheia\n");
    return;
  }
  fila->dados[fila->tamanho] = elem;
  fila->tamanho++;
}

int desenfileirar(FilaLinear *fila)
{
  if (fila->tamanho == 0)
  {
    fprintf(stderr, "Erro: Underflow - Fila vazia\n");
    return -1;
  }
  int removido = fila->dados[0];
  for (int i = 0; i < fila->tamanho - 1; i++)
  {
    fila->dados[i] = fila->dados[i + 1];
  }
  fila->tamanho--;
  return removido;
}

void mostrar(FilaLinear *fila)
{
  if (fila->tamanho == 0)
  {
    printf("Fila vazia!\n");
    return;
  }
  for (int i = 0; i < fila->tamanho; i++)
  {
    printf("%d ", fila->dados[i]);
  }
  printf("\n");
}

bool pesquisar(FilaLinear *fila, int elem)
{
  for (int i = 0; i < fila->tamanho; i++)
  {
    if (fila->dados[i] == elem)
    {
      return true;
    }
  }
  return false;
}

// void invertUsingStack(FilaLinear *fila)
// {
//   PilhaLinear stack = newPilhaLinear(fila->capacidade);
//   while (fila->tamanho > 0)
//   {
//     empilhar(&stack, desenfileirar(fila));
//   }
//   while (stack.n > 0)
//   {
//     enfileirar(fila, desempilhar(&stack));
//   }
// }

void mostrarRecursivo(FilaLinear *fila, int i)
{
  if (i == fila->tamanho)
  {
    printf("\n");
    return;
  }
  printf("%d ", fila->dados[i]);
  mostrarRecursivo(fila, i + 1);
}

int main()
{
  FilaLinear *fila = newFilaLinear(5);
  enfileirar(fila, 10);
  enfileirar(fila, 20);
  enfileirar(fila, 30);
  mostrar(fila);

  printf("Desenfileirado: %d\n", desenfileirar(fila));
  mostrar(fila);

  printf("Pesquisar 20: %s\n", pesquisar(fila, 20) ? "Encontrado" : "Não encontrado");
  printf("Pesquisar 50: %s\n", pesquisar(fila, 50) ? "Encontrado" : "Não encontrado");

  delFilaLinear(fila);
  return 0;
}