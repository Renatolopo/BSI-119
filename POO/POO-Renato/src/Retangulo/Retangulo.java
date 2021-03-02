package Retangulo;

public class Retangulo {
    private double comprimento;
    private double largura;

    public Retangulo(){
        comprimento = 1;
        largura = 1;
    }
    public void getPerimetro(){
        double perimetro = (this.comprimento +
                this.largura) * 2;
        System.out.printf("Perimetro: %.2f\n",perimetro);
    }
    public void getArea(){
        double area = this.comprimento * this.largura;
        System.out.printf("Área: %.2f\n", area);
    }

    public void setComprimento(double comprimento) {
        if(comprimento > 0 && comprimento < 20) {
            this.comprimento = comprimento;
        }
    }

    public void setLargura(double largura) {
        if(largura > 0 && largura < 20) {
            this.largura = largura;
        }
    }

    public double getComprimento() {
        return comprimento;
    }

    public double getLargura() {
        return largura;
    }
}
class TestRetangulo{
    public static void main(String[] args) {
        Retangulo r = new Retangulo();
        r.setComprimento(-2);
        r.setLargura(21);
        r.getArea();
        r.getPerimetro();
    }
}
