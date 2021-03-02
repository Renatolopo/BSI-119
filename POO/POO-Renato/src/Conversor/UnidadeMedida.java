package Conversor;

public class UnidadeMedida {
    private double valor;

    public void setValor(double valor) {
        this.valor = valor;
    }
    public double getValor() {
        return valor;
    }

    public void  converte(Celsius celsius){
        double val = (celsius.getValor() * 9/5) + 32;
        System.out.printf("%.2fº Celsius = %.2fº fahrenheit\n", celsius.getValor(), val);
    }
    public void  converte(Fahrenheit f){
        double val = (f.getValor() - 32) * 5/9;
        System.out.printf("%.2fº fahrenheit = %.2fº Celsius\n", f.getValor(), val);
    }
    public void converte(Galao g){
        double val = g.getValor() / 2.352;
        System.out.printf("%.2f Galões = %.2f Litros\n", g.getValor(), val);
    }
    public void converte(Litro l){
        double val = l.getValor() * 2.352;
        System.out.printf("%.2f Litros = %.2f Galoes\n", l.getValor(), val);
    }
    public void converte(Metro m){
        double val = m.getValor() * 3.281;
        System.out.printf("%.2f metros = %.2f pés\n", m.getValor(), val);
    }
    public void converte(Pes p){
        double val = p.getValor() / 3.281;
        System.out.printf("%.2f pes = %.2f metros\n",p.getValor(), val);
    }

    public void printVal(){
        System.out.println(this.getValor());
    }

}
class testConversor{
    public static void main(String[] args) {

        Fahrenheit f = new Fahrenheit(21);
        Celsius c = new Celsius(22);
        Metro m = new Metro(23);
        Pes p = new Pes(24);
        Litro l = new Litro(25);
        Galao g = new Galao(26);

        p.converte(m);
        m.converte(p);
        g.converte(l);
        l.converte(g);
        f.converte(c);
        c.converte(f);

        p.printVal();
        m.printVal();
        g.printVal();
        l.printVal();
        f.printVal();
        c.printVal();
    }
}