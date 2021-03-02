public class Carro {
    private String placa;
    private String modelo;
    private double valor;
    private int ano;

    Carro(String placa, String modelo, double valor, int ano){
        this.placa = placa;
        this.modelo = modelo;
        this.valor = valor;
        this.ano = ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public String recuperarDados(){
        return "Modelo: "+this.modelo+", Placa: "+this.placa+", Ano: "+this.ano+", Valor: "+this.valor+", IPVA: "+calcularIPVA();
    }

    public double calcularIPVA(){
        int idadeCarro = 2021 - this.ano;
        if(idadeCarro < 5){
            return (this.valor * 3)/100;
        }
        else if(idadeCarro < 10){
            return (this.valor * 2)/100;
        }
        else{
            return (this.valor * 1)/100;
        }
    }
}
class TestaCarro{
    public static void main(String[] args) {
        Carro c1 = new Carro("ppj321", "celta", 10000, 2009);

        String dados = c1.recuperarDados();
        System.out.println(dados);
    }
}
