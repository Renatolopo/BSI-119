public class Apolice {
    private String nomeSegurado;
    private int idade;
    private double valorPatrimonio;

    Apolice(String nome, int idade, double valor){
        this.nomeSegurado = nome;
        this.idade = idade;
        this.valorPatrimonio = valor;
    }

    String recuperarDados(){
       return  "Nome: "+this.nomeSegurado+", Idade: "+this.idade+", Patrimonio: "+this.valorPatrimonio+", Premio: "+this.calcularPremioApolice();
    }

    double calcularPremioApolice(){
        if (this.idade >= 18 && this.idade <= 25){
            return this.valorPatrimonio + (this.valorPatrimonio * 20)/100;
        }
        else if(this.idade > 25 && this.idade <= 36){
            return this.valorPatrimonio + (this.valorPatrimonio * 15)/100;
        }
        else if (this.idade > 36){
            return this.valorPatrimonio + (this.valorPatrimonio * 10)/100;
        }
        else{
            return this.valorPatrimonio;
        }
    }
}

class TestaApolice{
    public static void main(String[] args) {
        Apolice a1 = new Apolice("Renato", 20, 1500);
        String dados = a1.recuperarDados();
        System.out.println(dados);
    }
}
