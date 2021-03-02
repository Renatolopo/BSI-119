package Clinica;

import java.util.ArrayList;

public class Consulta {
    private Paciente paciente;
    private Medico medico;
    private String dataConsulta;
    private double valor;

    Consulta(Paciente paciente, Medico medico, String data){
        this.paciente = paciente;
        this.medico = medico;
        this.dataConsulta = data;

        if(this.paciente.possuiPlano()){
            this.valor = 0;
        }
        else if(this.medico.getEspecialidade() == "neurologia" ||
                this.medico.getEspecialidade() == "cardiologia"){
            this.valor = 300;
        }
        else{
            this.valor = 200;
        }
    }

    public void printConsultas(ArrayList<Consulta> consultas){
        for(Consulta consulta : consultas){
            System.out.println("---------------------------");
            System.out.printf("Paciente: %s   Medico:%s  Valor: %.2f " +
                    "Cod paciente: %d\n",consulta.paciente.getNome(),
                    consulta.medico.getNome(), consulta.valor,
                    consulta.paciente.getCodigo());
        }
    }
    
}
class TesteConsulta{
    public static void main(String[] args) {
        ArrayList<Consulta> consultas = new ArrayList<>();

        Paciente p1 = new Paciente("faustão", "12/2/2009",
                "m", true);
        Paciente p2 = new Paciente("Sakura", "09/07/2018",
                "F", false);
        Paciente p3 = new Paciente("michael jackson", "05/12/2011",
                "M",false);

        Medico m1 = new Medico("Robsom", 12, "neurologia");
        Medico m2 = new Medico("Robertão", 23, "come cu de curioso");

        Consulta c1 = new Consulta(p2,m1,"12/12/2000");
        consultas.add(c1);
        Consulta c2 = new Consulta(p1,m2,"12/09/2000");
        consultas.add(c2);
        Consulta c3 = new Consulta(p3,m2,"1/1/2001");
        consultas.add(c3);
        Consulta c4 = new Consulta(p3,m1,"12/02/2019");
        consultas.add(c4);

        c1.printConsultas(consultas);

    }
}