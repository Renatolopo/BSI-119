package ContaPopancaAnual;

public class ContaPopancaAnual {
    private static double taxaJurosAnual;
    private double saldo;

    public  ContaPopancaAnual(double saldo){
        this.saldo = saldo;
    }

    public static void setTaxaJurosAnual(double taxaJurosAnual) {
        ContaPopancaAnual.taxaJurosAnual = taxaJurosAnual;
    }

    public void ganhosAnuais(){
        this.saldo += (taxaJurosAnual * 100)/saldo;
    }
    public void consulta(){
        System.out.printf("Saldo inicial: %.2f\n",saldo);
        this.ganhosAnuais();
        System.out.printf("Saldo final: %.2f\n", saldo);
    }
}
class TestConta{
    public static void main(String[] args) {
        ContaPopancaAnual.setTaxaJurosAnual(5);
        ContaPopancaAnual c1 = new ContaPopancaAnual(2000);
        ContaPopancaAnual c2 = new ContaPopancaAnual(3000);

        c1.consulta();
        c2.consulta();
    }
}
