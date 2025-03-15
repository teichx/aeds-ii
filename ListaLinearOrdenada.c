#include <stdio.h>
#include <stdlib.h>

typedef struct ListaLinearOrdenada
{
  int *items;
  int max;
  int n;
} ListaLinearOrdenada;

ListaLinearOrdenada newListaLinear(int max)
{
  ListaLinearOrdenada lista;
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

void cleanup(ListaLinearOrdenada *lista)
{
  free(lista->items);
  lista->items = NULL;
  lista->max = 0;
  lista->n = 0;
}

void binaryInsert(ListaLinearOrdenada *lista, int item)
{
  if (lista->n == lista->max)
  {
    fprintf(stderr, "Overflow\n");
    exit(EXIT_FAILURE);
  }
  int start = 0;
  int end = lista->n - 1;
  int middle = 0;
  while (start <= end)
  {
    middle = (start + end) / 2;
    if (lista->items[middle] == item)
    {
      break;
    }
    if (lista->items[middle] < item)
    {
      start = middle + 1;
    }
    else
    {
      end = middle - 1;
    }
  }
  if (lista->items[middle] < item)
  {
    middle++;
  }
  for (int i = lista->n - 1; i >= middle; i--)
  {
    lista->items[i + 1] = lista->items[i];
  }
  lista->items[middle] = item;
  lista->n++;
}

int binaryRemove(ListaLinearOrdenada *lista, int item)
{
  int start = 0;
  int end = lista->n - 1;
  while (start <= end)
  {
    int middle = (start + end) / 2;
    if (lista->items[middle] == item)
    {
      for (int i = middle; i < lista->n; i++)
      {
        lista->items[i] = lista->items[i + 1];
      }
      lista->n--;
      return 1;
    }
    if (lista->items[middle] < item)
    {
      start = middle + 1;
    }
    else
    {
      end = middle - 1;
    }
  }
  return 0;
}

int removeStart(ListaLinearOrdenada *lista)
{
  return binaryRemove(lista, 0);
}

int removeEnd(ListaLinearOrdenada *lista)
{
  return binaryRemove(lista, lista->n - 1);
}

int removeMiddle(ListaLinearOrdenada *lista)
{
  return binaryRemove(lista, (int)((lista->n - 1) / 2));
}

void mostrar(ListaLinearOrdenada *lista)
{
  printf("Items: ");
  printf("[%d", lista->items[0]);
  for (int i = 1; i < lista->n; i++)
  {
    printf(", %d", lista->items[i]);
  }
  printf("]\n");
}

int IsOrdenada(ListaLinearOrdenada *lista)
{
  for (int i = 0; i < lista->n - 1; i++)
  {
    if (lista->items[i] > lista->items[i + 1])
    {
      return 0;
    }
  }
  return 1;
}

int binarySearch(ListaLinearOrdenada *lista, int item)
{
  int start = 0;
  int end = lista->n - 1;
  while (start <= end)
  {
    int middle = (start + end) / 2;
    if (lista->items[middle] == item)
    {
      return 1;
    }
    if (lista->items[middle] < item)
    {
      start = middle + 1;
    }
    else
    {
      end = middle - 1;
    }
  }
  return 0;
}

int main()
{
  ListaLinearOrdenada lista = newListaLinear(10);
  binaryInsert(&lista, 2);
  binaryInsert(&lista, 1);
  binaryInsert(&lista, 6);
  binaryInsert(&lista, 5);
  binaryInsert(&lista, 3);
  binaryInsert(&lista, 4);
  binaryInsert(&lista, 8);

  mostrar(&lista);
  printf("Ordered: %d\n", IsOrdenada(&lista));

  printf("First item: %d\n", removeStart(&lista));
  printf("Middle item: %d\n", removeMiddle(&lista));
  printf("Last item: %d\n", removeEnd(&lista));
  mostrar(&lista);

  return 0;
}
