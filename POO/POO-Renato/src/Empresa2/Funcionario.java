package Empresa2;

public abstract class Funcionario {
    private String nome;
    private int cpf;
    private String sexo;
    private int idade;
    private double salario;
    
    public Funcionario(String nome, int cpf, int idade, 
                       double salario, String sexo){
        this.nome = nome;
        this.cpf = cpf;
        this.salario = salario;
        this.idade = idade;
        this.sexo = sexo;
    }


    public void getBonificacao(){

    }

    public double getSalario() {
        return salario;
    }

    public String getNome() {
        return nome;
    }
}
