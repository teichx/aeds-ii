class ListaLinear {
  public int[] items;
  public int max;
  public int n;

  public ListaLinear(int max) {
    this.items = new int[max];
    this.max = max;
    this.n = 0;
  }

  public void inserir(int elem, int pos) {
    if (this.n == this.max) throw new RuntimeException("Overflow");
    if (pos < 0 || pos > this.max) throw new RuntimeException("Position overflow");

    for (int i = this.n - 1; i >= pos; i--) {                
      this.items[i+1] = this.items[i];
    }
    this.items[pos] = elem;
    this.n++;
  }

  public void inserirInicio(int elem) {
    inserir(elem, 0);
  }

  public void inserirFim(int elem) {
    inserir(elem, this.n);
  }

  public void remover(int pos) {
    if (this.n == 0) throw new RuntimeException("Underflow");
    if (pos < 0 || pos > this.max) throw new RuntimeException("Position overflow");

    for (int i = pos; i < this.n; i++) {                
      this.items[i] = this.items[i+1];
    }
    this.items[this.n] = 0;
    this.n--;
  }

  public void removerInicio() {
    remover(0);
  }

  public void removerFim() {
    remover(this.n - 1);
  }

  public void mostrar() {
    for (int i = 0; i < this.n; i++) {
      System.out.println(this.items[i]);
    }
  }

  public boolean pesquisar(int elem) {
    for (int i = 0; i < this.n; i++) {
      if (this.items[i] == elem) return true;
    }
    return false;
  }
}

public class LinearList {
  public static void main(String args[]) {
    ListaLinear lista = new ListaLinear(10);
    lista.inserirFim(10);
    lista.inserirFim(20);
    lista.inserirFim(30);
    lista.inserirFim(40);
    lista.inserirFim(50);
    lista.mostrar();
    lista.removerInicio();
    lista.removerFim();
    lista.mostrar();
    System.out.println(lista.pesquisar(20));
  }
}