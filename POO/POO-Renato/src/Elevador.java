public class Elevador {
    private int andarAtual;
    private int totalDeAndares;
    private int capacidadeElevador;
    private int quantidadeDePessoas;

    Elevador(int capacidadeElevador, int totalDeAndares){
        this.capacidadeElevador = capacidadeElevador;
        this.totalDeAndares = totalDeAndares;
        this.andarAtual = 0;
        this.quantidadeDePessoas = 0;
    }
    public void entrar(){
        if(this.quantidadeDePessoas < this.capacidadeElevador){
            this.quantidadeDePessoas ++;
            System.out.println("Uma pessoa entrou");
        }
        else{
            System.out.println("Capacidade maxima do elevador atingida");
        }
    }
    public void sai(){
        if(this.quantidadeDePessoas > 0){
            this.quantidadeDePessoas --;
            System.out.println("Uma pessoa saiu");
        }
        else{
            System.out.println("Elevador vazio");
        }
    }
    public void sobe(){
        if(this.andarAtual < this.totalDeAndares){
            this.andarAtual ++;
            System.out.println("Subiu um andar");
        }
        else{
            System.out.println("Não é possivel subir mais, a não ser q vc tenha um avião");
        }
    }
    public void desce(){
        if(this.andarAtual > 0){
            this.andarAtual --;
            System.out.println("Desceu um andar");
        }
        else{
            System.out.println("não e possivel descer alem do chão, a não ser que vc tenha cometido algum crime");
        }
    }
}
class TesteElevador{
    public static void main(String[] args) {
        Elevador e = new Elevador(5,12);
        e.sobe();
        e.entrar();
        e.entrar();
        e.sobe();
        e.sobe();
        e.sobe();
        e.desce();
        e.entrar();
        e.entrar();
        e.entrar();
        e.entrar();
        e.sobe();
        e.sobe();
        e.sobe();
        e.sobe();
        e.sobe();
        e.sobe();
        e.sobe();
        e.sobe();
        e.sobe();
        e.sobe();
        e.sobe();
        e.sobe();
        e.desce();
        e.desce();
        e.entrar();
        e.sai();
        e.sai();
        e.entrar();
        e.desce();
        e.desce();
        e.desce();
        e.desce();
        e.desce();
        e.desce();
        e.desce();
        e.desce();
        e.desce();
        e.desce();
        e.desce();
        e.desce();
    }
}
