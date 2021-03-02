import java.util.Scanner;

public class Fibonacci {
    private int n;

    public void setN(int n) {
        this.n = n;
    }
    public void sequenciaFibonacci(){
        int anterio = 1;
        int atual = 0;
        for(int i=0; i < this.n; i++){
            System.out.println(atual);
            int aux = atual;
            atual = atual+anterio;
            anterio = aux;
        }

    }
}
class TesteFibonacci{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Quantos números da sequencia de fibonacci vc deseja ver: ");
        int n = scan.nextInt();

        Fibonacci f = new Fibonacci();
        f.setN(n);
        f.sequenciaFibonacci();
    }
}
