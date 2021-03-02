package Fatura;

public class Fatura {
    private int numero;
    private String descricao;
    private int quantidade;
    private double preco;

    public Fatura(int numero, String descricao,
                  int quantidade, double preco){
        this.numero = numero;
        this.descricao = descricao;
        this.quantidade = quantidade;
        this.preco = preco;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public double getPreco() {
        return preco;
    }

    public int getNumero() {
        return numero;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public String getDescricao() {
        return descricao;
    }

    public double getTotalFatura(){
        double value = this.quantidade * this.preco;
        return value;
    }
}

class FaturaTest{
    public static void main(String[] args) {
        Fatura f = new Fatura(2,"Mouse",
                2,45.0);
        double total = f.getTotalFatura();
        System.out.printf("Total: %.2f",total);
    }
}

