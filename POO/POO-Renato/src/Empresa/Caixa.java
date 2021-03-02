package Empresa;

public class Caixa {
    private double saldo;

    Caixa(double saldo){
        this.saldo = saldo;
    }

    public void pagar(Dolar valor){
        double total = 5.37 * valor.getValor();
        this.saldo -= total;
        System.out.printf("Valor pago: R$ %.2f\n",total);
    }
    public void pagar(Real valor){
        this.saldo -= valor.getValor();
        System.out.printf("Valor pago: R$ %.2f\n",valor.getValor());
    }
    public void receber(Dolar valor){
        double total = 5.37 * valor.getValor();
        this.saldo += total;
        System.out.printf("Valor recebido: R$ %.2f\n",total);
    }
    public void receber(Real valor){
        this.saldo += valor.getValor();
        System.out.printf("Valor recebido: R$ %.2f\n",valor.getValor());
    }
    public void consultaSaldo(){
        System.out.printf("Saldo atual: R$ %.2f\n",this.saldo);
    }
}
