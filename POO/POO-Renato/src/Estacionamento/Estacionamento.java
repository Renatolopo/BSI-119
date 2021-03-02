package Estacionamento;

public class Estacionamento {
    private int qtdHoras;

    public void setQtdHoras(int qtdHoras) {
        this.qtdHoras = qtdHoras;
    }
    public void getTotal(){
        double valTotal;
        if(this.qtdHoras <= 3){
            valTotal = 2;
        }
        else{
            valTotal = (qtdHoras - 3) * 0.5 + 2;
        }
        System.out.printf("Total: R$ %.2f\n", valTotal);
    }
}
class TestEstacionamento{
    public static void main(String[] args) {
        Estacionamento carro1 = new Estacionamento();
        carro1.setQtdHoras(4);
        carro1.getTotal();
    }
}
