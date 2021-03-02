public class Triangulo{
    private double lado1;
    private double lado2;
    private double lado3;

    Triangulo(double lado1, double lado2, double lado3){
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.lado3 = lado3;
    }

    void setLados(double l1, double l2, double l3){
        this.lado1 = l1;
        this.lado2 = l2;
        this.lado3 = l3;
    }
    double maiorLado(){
        double maior = 0;
        if(this.lado1 > maior){
           maior = this.lado1;
        }
        if(this.lado2 > maior){
            maior = this.lado2;
        }
        if(this.lado3 > maior){
            maior = this.lado3;
        }
        return maior;
    }
    double menorLado(){
        double menor = 999999;
        if(this.lado1 < menor){
            menor = this.lado1;
        }
        if(this.lado2 < menor){
            menor = this.lado2;
        }
        if(this.lado3 < menor){
            menor = this.lado3;
        }
        return menor;
    }
    String tipoDoTriangulo(){
        String tipo = " ";
        if(this.lado1 == this.lado2 && this.lado2 == this.lado3){
            tipo = "Equilátero";
        }
        else if(this.lado1 == this.lado2 || this.lado1 == this.lado3 || this.lado2 == this.lado3){
            tipo = "Isósceles";
        }
        else if(this.lado1 != this.lado2 && this.lado1 != this.lado3 && this.lado2 != this.lado3){
            tipo = "Escaleno";
        }
        return tipo;
    }
}


class TestaTriangulo {
    public static void main(String[] args) {
        Triangulo triangulo1 = new Triangulo(2,3,4);
        double maior = triangulo1.maiorLado();
        System.out.println("O maior lado é mede: "+ maior);
        double menor = triangulo1.menorLado();
        System.out.println("O maior lado é mede: "+ menor);
        String tipo = triangulo1.tipoDoTriangulo();
        System.out.println("O triangulo é do tipo: "+ tipo);
    }
}
