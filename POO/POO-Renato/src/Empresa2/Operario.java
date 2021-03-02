package Empresa2;

public class Operario extends Funcionario{
    private boolean faltou;

    public Operario(String nome, int cpf, int idade,
                     double salario, String sexo, boolean faltou){
        super(nome, cpf, idade, salario, sexo);
        this.faltou = faltou;
    }


    @Override
    public void getBonificacao() {
        double bonificacao = 0;
        if(!faltou){
            bonificacao = (this.getSalario() * 5)/100;
        }
        System.out.printf("O %s é Operario e recebeu bonificação de R$%.2f\n",
                this.getNome(), bonificacao);
    }
}
