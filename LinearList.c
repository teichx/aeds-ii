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

void inserirInicio(ListaLinear *lista, int elem)
{
  inserir(lista, elem, 0);
}

void inserirFim(ListaLinear *lista, int elem)
{
  inserir(lista, elem, lista->n);
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

int removerInicio(ListaLinear *lista)
{
  remover(lista, 0);
}

int removerFim(ListaLinear *lista)
{
  remover(lista, lista->n - 1);
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

void reverse(ListaLinear *lista)
{
  for (int i = 0; i < lista->n / 2; i++)
  {
    int temp = lista->items[i];
    lista->items[i] = lista->items[lista->n - 1 - i];
    lista->items[lista->n - 1 - i] = temp;
  }
}

void recursiveReverse(ListaLinear *lista, int i)
{
  if (i < lista->n / 2)
  {
    int temp = lista->items[i];
    lista->items[i] = lista->items[lista->n - 1 - i];
    lista->items[lista->n - 1 - i] = temp;
    recursiveReverse(lista, i + 1);
  }
}

int main()
{
  ListaLinear lista = newListaLinear(5);
  inserirInicio(&lista, 2);
  inserirInicio(&lista, 1);
  inserir(&lista, 3, 2);
  inserirFim(&lista, 4);

  mostrar(&lista);
  reverse(&lista);
  mostrar(&lista);
  recursiveReverse(&lista, 0);
  mostrar(&lista);

  // mostrar(&lista);
  // printf("Pesquisar 5: %d\n", pesquisar(&lista, 5));
  // printf("Pesquisar 3: %d\n", pesquisar(&lista, 3));
  // printf("Remover 3: %d\n", remover(&lista, 2));
  // mostrar(&lista);
  // printf("Remover Inicio: %d\n", removerInicio(&lista));
  // mostrar(&lista);
  // printf("Remover Fim: %d\n", removerFim(&lista));
  // mostrar(&lista);
  // delListaLinear(&lista);
  return 0;
}
