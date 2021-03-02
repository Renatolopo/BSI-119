package Clinica;

public class Paciente {
    static private int codigo = 0;
    private String nome;
    private String dataNascimento;
    private String sexo;
    private boolean possuiPlanoDeSaude;

    Paciente(String nome, String data, String sexo, boolean plano){
        this.codigo ++;
        this.nome = nome;
        this.dataNascimento = data;
        this.sexo = sexo;
        this.possuiPlanoDeSaude = plano;
    }
    public boolean possuiPlano(){
        return this.possuiPlanoDeSaude;
    }

    public String getNome() {
        return nome;
    }

    public  int getCodigo() {
        return this.codigo;
    }
}
