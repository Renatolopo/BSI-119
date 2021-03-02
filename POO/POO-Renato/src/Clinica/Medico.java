package Clinica;

public class Medico {
    private String nome;
    private int crm;
    private String especialidade;

    Medico(String nome, int crm, String especialidade){
        this.nome = nome;
        this.crm = crm;
        this.especialidade = especialidade;
    }

    public String getEspecialidade() {
        return especialidade;
    }

    public String getNome() {
        return nome;
    }
}
