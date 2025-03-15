class PilhaLinear {
    private int[] items;
    private int topo;

    public PilhaLinear(int max) {
        items = new int[max];
        topo = -1;
    }

    public void empilhar(int elemento) {
        if (topo < items.length - 1) {
            topo++;
            items[topo] = elemento;
        } else {
            throw new RuntimeException("Stack overflow");
        }
    }

    public int desempilhar() {
        if (topo != -1) {
            int elemento = items[topo];
            topo--;
            return elemento;
        } else {
            throw new RuntimeException("Stack underflow");
        }
    }

    public void mostrar() {
        if (topo == -1) return;
        for (int i = 0; i <= topo; i++) {
            System.out.println(items[i]);
        }
    }

    public boolean pesquisar(int elemento) {
        for (int i = 0; i <= topo; i++) {
            if (items[i] == elemento) {
                return true;
            }
        }
        return false;
    }
}