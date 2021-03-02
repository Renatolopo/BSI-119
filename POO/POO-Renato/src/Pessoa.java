public class Pessoa {
    private String nome;
    private  int idade;
    private float peso;
    private double altura;

    Pessoa(String nome, int idade, float peso, double altura){
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
        this.altura = altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setPeso(float peso) {
        this.peso = peso;
    }

    public double getIMC(){
        return this.peso/(this.altura * this.altura);
    }

    public String categoria(){
        double imc = this.getIMC();
        if(imc < 18.5){
            return "abaixo do peso";
        }
        else if(imc < 25){
            return "peso normal";
        }
        else if(imc < 30){
            return "sobrepeso";
        }
        else if(imc < 35){
            return "obesidade grau I";
        }
        else if(imc < 40){
            return "obesidade grau II";
        }
        else{
            return "obesidade grau III";
        }
    }
}
class TestaPessoa{
    public static void main(String[] args) {
        Pessoa p = new Pessoa("renato", 20, 63, 1.70);
        p.setNome("renato");
        p.setAltura(1.70);
        p.setPeso(63);
        p.setIdade(20);

        System.out.printf("Imc: %.2f - Categoria: %s",p.getIMC(),p.categoria());
    }
}
