package Data;

import java.util.ArrayList;
import java.util.List;

public class Date {
    private String date1;
    private String date2;
    static List<String> nomeMes = new ArrayList<String>();

    public static void setNomeMes(List<String> nomeMes) {
        Date.nomeMes = nomeMes;
    }

    public  Date(int dia, int mes, int ano){
        this(dia+"/"+mes+"/"+ano);
    }
    public  Date(String date){
        String listDate[] = date.split("/");
        int dia = Integer.parseInt(listDate[0]);
        int mes = Integer.parseInt(listDate[1]);
        int ano = Integer.parseInt(listDate[2]);
        setDados(dia, mes, ano);

    }

    public void setDados(int dia, int mes, int ano){
        if(dia <= 31 && dia > 0 && mes > 0 && mes <= 12 &&
                ano > 0){
            this.date1 = dia+"/"+mes+"/"+ano;
            this.date2 = dia+" de "+Date.nomeMes.get(mes - 1)+
                    " de "+ ano;
        }
        else{
            System.out.println("Data invalida");
        }
    }

    public void consultaData(){
        System.out.printf("%s\n%s\n", this.date1, this.date2);
    }

    public void incrementDia(){
        String listDate[] = this.date1.split("/");
        int dia = Integer.parseInt(listDate[0]);
        int mes = Integer.parseInt(listDate[1]);
        int ano = Integer.parseInt(listDate[2]);

        dia ++;
        if(dia > 31){
            dia = 1;
            mes ++;
        }
        if(mes > 12){
            mes = 1;
            ano ++;
        }
        setDados(dia, mes, ano);
    }
}
class testDate{
    public static void main(String[] args) {
        List<String> nomeMes = new ArrayList<String>();
        nomeMes.add("Janeiro");
        nomeMes.add("Fevereiro");
        nomeMes.add("Março");
        nomeMes.add("Abril");
        nomeMes.add("Maio");
        nomeMes.add("Junho");
        nomeMes.add("Julho");
        nomeMes.add("Agosto");
        nomeMes.add("Setembro");
        nomeMes.add("Otubro");
        nomeMes.add("Novembro");
        nomeMes.add("Dezembro");

        Date.setNomeMes(nomeMes);

        Date d = new Date("31/12/2021");
        d.consultaData();
        d.incrementDia();
        d.consultaData();
    }
}