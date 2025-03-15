#include <stdio.h>
#include <stdlib.h>

typedef struct ListaLinear
{
  int *items;
  int max;
  int n;
} ListaLinear;

ListaLinear newListaLinear(int max)
{
  ListaLinear lista;
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

void delListaLinear(ListaLinear *lista)
{
  free(lista->items);
}

void inserirInicio(ListaLinear *lista, int elem)
{
  if (lista->n == lista->max)
  {
    fprintf(stderr, "Erro: Overflow\n");
    exit(EXIT_FAILURE);
  }

  for (int i = lista->n - 1; i >= 0; i--)
  {
    lista->items[i + 1] = lista->items[i];
  }
  lista->items[0] = elem;
  lista->n++;
}

void inserirFim(ListaLinear *lista, int elem)
{
  if (lista->n == lista->max)
  {
    fprintf(stderr, "Erro: Overflow\n");
    exit(EXIT_FAILURE);
  }

  lista->items[lista->n] = elem;
  lista->n++;
}

void inserir(ListaLinear *lista, int elem, int pos)
{
  if (lista->n == lista->max)
  {
    fprintf(stderr, "Erro: Overflow\n");
    exit(EXIT_FAILURE);
  }
  if (pos < 0 || pos > lista->max)
  {
    fprintf(stderr, "Erro: Posição inválida\n");
    exit(EXIT_FAILURE);
  }

  for (int i = lista->n - 1; i >= pos; i--)
  {
    lista->items[i + 1] = lista->items[i];
  }
  lista->items[pos] = elem;
  lista->n++;
}

int removerInicio(ListaLinear *lista)
{
  if (lista->n == 0)
  {
    fprintf(stderr, "Erro: Underflow\n");
    exit(EXIT_FAILURE);
  }

  int elem = lista->items[0];
  for (int i = 0; i < lista->n; i++)
  {
    lista->items[i] = lista->items[i + 1];
  }
  lista->n--;
  return elem;
}

int removerFim(ListaLinear *lista)
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

int remover(ListaLinear *lista, int pos)
{
  if (lista->n == 0)
  {
    fprintf(stderr, "Erro: Underflow\n");
    exit(EXIT_FAILURE);
  }
  if (pos < 0 || pos > lista->max)
  {
    fprintf(stderr, "Erro: Posição inválida\n");
    exit(EXIT_FAILURE);
  }

  int elem = lista->items[pos];
  for (int i = pos; i < lista->n; i++)
  {
    lista->items[i] = lista->items[i + 1];
  }
  lista->n--;
  return elem;
}

void mostrar(ListaLinear *lista)
{
  printf("Items: ");
  printf("[%d", lista->items[0]);
  for (int i = 1; i < lista->n; i++)
  {
    printf(", %d", lista->items[i]);
  }
  printf("]\n");
}

int pesquisar(ListaLinear *lista, int elem)
{
  for (int i = 0; i < lista->n; i++)
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
  ListaLinear lista = newListaLinear(5);
  inserirInicio(&lista, 2);
  inserirInicio(&lista, 1);
  inserir(&lista, 3, 2);
  inserirFim(&lista, 4);

  mostrar(&lista);
  printf("Pesquisar 5: %d\n", pesquisar(&lista, 5));
  printf("Pesquisar 3: %d\n", pesquisar(&lista, 3));
  printf("Remover 3: %d\n", remover(&lista, 2));
  mostrar(&lista);
  printf("Remover Inicio: %d\n", removerInicio(&lista));
  mostrar(&lista);
  printf("Remover Fim: %d\n", removerFim(&lista));
  mostrar(&lista);
  delListaLinear(&lista);
  return 0;
}
