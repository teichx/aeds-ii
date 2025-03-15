/*
Welcome to JDoodle!

You can execute code here in 88 languages. Right now you’re in the Java IDE.

  1. Click the orange Execute button ▶ to execute the sample code below and see how it works.

  2. Want help writing or debugging code? Type a query into JDroid on the right hand side ---------------->

  3.Try the menu buttons on the left. Save your file, share code with friends and open saved projects.

Want to change languages? Try the search bar up the top.
*/

class FilaLinear {
  private int[] fila;
  private int tamanho, capacidade;

  public FilaLinear(int max) {
      this.capacidade = max;
      this.fila = new int[max];
      this.tamanho = 0;
  }

  public void enfileirar(int elem) {
      if (tamanho == capacidade) {
          throw new RuntimeException("Overflow: Fila cheia");
      }
      fila[tamanho] = elem;
      tamanho++;
  }

  public int desenfileirar() {
      if (tamanho == 0) {
          throw new RuntimeException("Underflow: Fila vazia");
      }
      int removido = fila[0];
      for (int i = 0; i < tamanho - 1; i++) {
          fila[i] = fila[i + 1];
      }
      tamanho--;
      return removido;
  }

  public void mostrar() {
      if (tamanho == 0) {
          System.out.println("Fila vazia!");
          return;
      }
      for (int i = 0; i < tamanho; i++) {
          System.out.print(fila[i] + " ");
      }
      System.out.println();
  }

  public boolean pesquisar(int elem) {
      for (int i = 0; i < tamanho; i++) {
          if (fila[i] == elem) {
              return true;
          }
      }
      return false;
  }
}


public class LinearQueue {
  public static void main(String args[]) {
    FilaLinear fila = new FilaLinear(5);
    fila.enfileirar(10);
    fila.enfileirar(20);
    fila.enfileirar(30);
    fila.enfileirar(40);
    fila.enfileirar(50);
    fila.mostrar();
    System.out.println("Elemento removido: " + fila.desenfileirar());
    fila.mostrar();
    System.out.println("Elemento removido: " + fila.desenfileirar());
    fila.mostrar();
    System.out.println("Elemento removido: " + fila.desenfileirar());
    fila.mostrar();
    System.out.println("Elemento removido: " + fila.desenfileirar());
  }
}