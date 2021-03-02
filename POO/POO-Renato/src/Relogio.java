import java.lang.reflect.Array;

public class Relogio {
    private int hora;
    private int minutos;
    private int segundos;
    public static final int limite = 60;

    public Relogio(int hora, int minutos, int segundos){
        this.hora = hora;
        this.minutos = minutos;
        this.segundos = segundos;
    }
    public Relogio(int hora, int minutos){
        this.hora = hora;
        this.minutos = minutos;
        this.segundos = 0;
    }
    public Relogio(int hora){
        this.hora = hora;
        this.minutos = 0;
        this.segundos = 0;
    }

    public void acertaHora(int hora, int minuto, int segundos){
        if(hora <= limite){
            this.hora = hora;
        }
        if(minuto <= limite){
            this.minutos = minuto;
        }
        if(segundos <= limite){
            this.segundos = segundos;
        }



    }
    public void acertaHora(String horario){
        String h[] = horario.split(":");
        int hora = Integer.parseInt(h[0]);
        int minuto = Integer.parseInt(h[1]);
        int segundos  = Integer.parseInt(h[2]);

        acertaHora(hora,minuto,segundos);
    }

    public void getHoraAtual(){
        System.out.printf("%d:%d:%d\n", this.hora, this.minutos, this.segundos);
    }
}
class TesteRelogio{
    public static void main(String[] args) {
        Relogio r = new Relogio(12,30);
        r.getHoraAtual();
        r.acertaHora("12:34:57");
        r.getHoraAtual();
        r.acertaHora(84,23,30);
        r.getHoraAtual();
        r.acertaHora(9,15,12);
        r.getHoraAtual();
    }
}
