public class Data {
    private int dia;
    private int mes;
    private int ano;

    Data(int dia, int mes, int ano){
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public void setDia(int dia) {
        this.dia = dia;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    String formatoBrasileiro(){
        return this.dia+"/"+this.mes+"/"+this.ano;
    }

    String formatoAmericano(){
        return this.mes+"/"+this.dia+"/"+this.ano;
    }
}
class TestarData{
    public static void main(String[] args) {
        Data d1 = new Data(28,01,2021);

        System.out.println("Formato BR: "+ d1.formatoBrasileiro());
        System.out.println("Formato Americano: "+ d1.formatoAmericano());
    }
}
