import java.util.Scanner;

public class NPrimeiros {
    private int n;

    public void setN(int n) {
        this.n = n;
    }
    public void printPrimos(){
        int numerosPrimos = 0;
        int numeroEmVerificacao = 2;
        do{
            int i;
            for(i=2;i < numeroEmVerificacao;i++){
                if(numeroEmVerificacao % i == 0){
                    break;
                }
            }
            if(i == numeroEmVerificacao){
                numerosPrimos ++;
                System.out.println(numeroEmVerificacao);
            }
            numeroEmVerificacao++;
        }while (numerosPrimos <= this.n);
    }
}
class TestePrimos{
    public static void main(String[] args) {
        System.out.print("informe a quantidade de numeros primos que deseja ver: ");
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        NPrimeiros p = new NPrimeiros();
        p.setN(n);
        p.printPrimos();
    }
}
