package Empregado;

public class Empregado {
    private String nome;
    private String sobrenome;
    private double salario;

    public Empregado(String nome, String sobrenome,
                     double salario){
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.salario = salario;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public void setSobrenome(String sobrenome) {
        this.sobrenome = sobrenome;
    }

    public String getNome() {
        return nome;
    }

    public double getSalario() {
        return salario;
    }

    public String getSobrenome() {
        return sobrenome;
    }

    public double getSalarioAnual(){
        return this.salario * 12;
    }
    public void Aumento(int percent){
        this.salario += (percent*this.salario)/100;
    }
    public void imprimeSalario(){
        double salario = this.getSalarioAnual();
        System.out.printf("%s recebe R$ %.2f\n",this.nome, salario);
    }
}
class TesteEmpregado{
    public static void main(String[] args) {
        Empregado e1 = new Empregado("renato","lopo",
                1200.0);
        Empregado e2 = new Empregado("faustao","silva",
                800000);

        e1.imprimeSalario();
        e2.imprimeSalario();

        e1.Aumento(15);

        e1.imprimeSalario();
    }
}