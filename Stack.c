#include <stdio.h>
#include <stdlib.h>

typedef struct PilhaLinear
{
  int *items;
  int max;
  int n;
} PilhaLinear;

PilhaLinear newPilhaLinear(int max)
{
  PilhaLinear lista;
  lista.items = (int *)malloc(max * sizeof(int));
  if (lista.items == NULL)
  {
    fprintf(stderr, "Erro: Falha na alocação de memória\n");
    exit(EXIT_FAILURE);
  }
  lista.max = max;
  lista.n = 0;
  return lista;
}

void delListaLinear(PilhaLinear *lista)
{
  free(lista->items);
}

void empilhar(PilhaLinear *lista, int elem)
{
  if (lista->n == lista->max)
  {
    fprintf(stderr, "Erro: Overflow\n");
    exit(EXIT_FAILURE);
  }

  lista->items[lista->n] = elem;
  lista->n++;
}

int desempilhar(PilhaLinear *lista)
{
  if (lista->n == 0)
  {
    fprintf(stderr, "Erro: Underflow\n");
    exit(EXIT_FAILURE);
  }

  int elem = lista->items[lista->n - 1];
  lista->n--;
  return elem;
}

void mostrar(PilhaLinear *lista)
{
  printf("Items: ");
  printf("[%d", lista->items[lista->n - 1]);
  for (int i = lista->n - 2; i >= 0; i--)
  {
    printf(", %d", lista->items[i]);
  }
  printf("]\n");
}

int pesquisar(PilhaLinear *lista, int elem)
{
  for (int i = lista->n - 1; i > 0; i--)
  {
    if (lista->items[i] == elem)
    {
      return 1;
    }
  }
  return 0;
}

int main()
{
  PilhaLinear lista = newPilhaLinear(5);
  empilhar(&lista, 2);
  empilhar(&lista, 1);
  empilhar(&lista, 3);
  empilhar(&lista, 4);

  mostrar(&lista);
  printf("Pesquisar 5: %d\n", pesquisar(&lista, 5));
  printf("Pesquisar 3: %d\n", pesquisar(&lista, 3));
  printf("Desempilhar: %d\n", desempilhar(&lista));
  mostrar(&lista);
  printf("Desempilhar: %d\n", desempilhar(&lista));
  mostrar(&lista);

  return 0;
}
