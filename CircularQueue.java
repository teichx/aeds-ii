class FilaCircular {
  private int[] fila;
  private int inicio, fim, tamanho, capacidade;

  public FilaCircular(int max) {
      this.capacidade = max;
      this.fila = new int[max];
      this.inicio = 0;
      this.fim = -1;
      this.tamanho = 0;
  }

  public void enfileirar(int elem) {
      if (tamanho == capacidade) {
          throw new RuntimeException("Overflow: Fila cheia");
      }
      fim = (fim + 1) % capacidade;
      fila[fim] = elem;
      tamanho++;
  }

  public int desenfileirar() {
      if (tamanho == 0) {
          throw new RuntimeException("Underflow: Fila vazia");
      }
      int removido = fila[inicio];
      inicio = (inicio + 1) % capacidade;
      tamanho--;
      return removido;
  }

  public void mostrar() {
      if (tamanho == 0) {
          System.out.println("Fila vazia!");
          return;
      }
      for (int i = 0; i < tamanho; i++) {
          System.out.print(fila[(inicio + i) % capacidade] + " ");
      }
      System.out.println();
  }

  public boolean pesquisar(int elem) {
      for (int i = 0; i < tamanho; i++) {
          if (fila[(inicio + i) % capacidade] == elem) {
              return true;
          }
      }
      return false;
  }
}

public class CircularQueue {
  public static void main(String args[]) {
    FilaCircular queue = new FilaCircular(10);
    queue.enfileirar(10);
    queue.enfileirar(20);
    queue.enfileirar(30);

    System.out.println(queue.desenfileirar());
    queue.enfileirar(40);
    queue.enfileirar(50);

    queue.mostrar();
    
    System.out.println(queue.pesquisar(20));
  }
}