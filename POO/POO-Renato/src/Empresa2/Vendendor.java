package Empresa2;

public class Vendendor extends  Funcionario{
    public double vendas;

    public Vendendor(String nome, int cpf, int idade,
                   double salario, String sexo, double vendas){
        super(nome, cpf, idade, salario, sexo);
        this.vendas = vendas;
    }

    @Override
    public void getBonificacao() {
        double bonificacao = (vendas * 1)/100;
        System.out.printf("O %s é vendendor e recebeu bonificação de R$%.2f\n",
                this.getNome(), bonificacao);
    }
}
