package Date;

public class Date {
    private int dia;
    private int mes;
    private int ano;

    public void setMes(int mes) {
        this.mes = mes;
        if(this.getMes() < 1){
            setMes(1);
        }
    }

    public void setDia(int dia) {
        this.dia = dia;
        if(getDia() < 1){
            setDia(1);
        }
    }

    public void setAno(int ano) {
        if(ano == 0) {
            this.ano = 1;
        }else {
            this.ano = ano;
        }
    }

    public int getAno() {
        return ano;
    }

    public int getDia() {
        return dia;
    }

    public int getMes() {
        return mes;
    }

    public void displayDate(){
        System.out.printf("%d/%d/",getDia(),getMes());
        if(this.ano < 0){
            int ano = this.ano * (-1);
            System.out.printf("%d  a.C.\n",ano);
        }else{
            System.out.printf("%d \n", this.ano);
        }
    }

}
class DataTest{
    public static void main(String[] args) {
        Date d = new Date();
        d.setDia(12);
        d.setMes(02);
        d.setAno(-90);

        d.displayDate();
    }
}