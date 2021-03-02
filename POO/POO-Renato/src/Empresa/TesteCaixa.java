package Empresa;

public class TesteCaixa {
    public static void main(String[] args) {
        Caixa caixa = new Caixa(89009);

        Dolar v1 = new Dolar(20);
        caixa.pagar(v1);
        Real v3 = new Real(34);
        caixa.pagar(v3);
        Dolar v2 = new Dolar(40);
        caixa.receber(v2);
        Real v4 = new Real(50);
        caixa.receber(v4);

        caixa.consultaSaldo();
    }
}
