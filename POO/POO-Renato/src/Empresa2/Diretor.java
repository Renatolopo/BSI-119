package Empresa2;

public class Diretor extends Funcionario{
    public boolean bateuMetaDeLucro;
    public double lucro;

    public Diretor(String nome, int cpf, int idade,
                   double salario, String sexo,
                   boolean bateuLucro, double lucro){
        super(nome, cpf, idade, salario, sexo);
        this.bateuMetaDeLucro = bateuLucro;
        this.lucro = lucro;
    }

    @Override
    public void getBonificacao() {
        double bonificacao = 0;
        if(bateuMetaDeLucro){
            bonificacao = (this.lucro * 10)/100;
        }
        System.out.printf("O %s é Diretor e recebeu bonificação de R$%.2f\n", this.getNome(),
                bonificacao);
    }
}
