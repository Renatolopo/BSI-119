package Empresa2;

public class TesteFuncionario {
    public static void main(String[] args) {
        Diretor d = new Diretor("paulin", 123, 43,
                12000, "M", false, 78000);
        Operario o = new Operario("Carlão", 343, 34,
                2000, "M", true);
        Vendendor v = new Vendendor("Jesica", 653, 23,
                1800, "F", 10);

        d.getBonificacao();
        o.getBonificacao();
        v.getBonificacao();
    }
}
