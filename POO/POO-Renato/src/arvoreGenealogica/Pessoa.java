package arvoreGenealogica;

public class Pessoa {
    private String nome;
    private int idade;
    private Pessoa pai;
    private Pessoa mae;

    public Pessoa(String nome, int idade){
        this(nome, idade, null, null);
    }
    public Pessoa(String nome, int idade, Pessoa pai, Pessoa mae){
        this.nome = nome;
        this.idade = idade;
        this.pai =pai;
        this.mae = mae;
    }

    public void obterParentesco(Pessoa p1){
        if(p1.pai == this){
            System.out.printf("%s é pai de %s\n", this.nome, p1.nome);
        }
        else if(p1.mae == this){
            System.out.printf("%s é mãe de %s\n", this.nome, p1.nome);
        }
        else if(this.pai == p1 || this.mae == p1){
            System.out.printf("%s é filho de %s\n", this.nome, p1.nome);
        }
        else if(this.pai == p1.pai || this.mae == p1.mae){
            System.out.printf("%s é irmão de %s\n", this.nome, p1.nome);
        }
        else if(this.pai.pai == p1.pai || this.mae.mae == p1.mae){
            System.out.printf("%s é sobrinho de %S\n", this.nome, p1.nome);
        }
        else if(this.pai == p1.pai.pai || this.mae == p1.mae.mae){
            System.out.printf("%s é tio de %s\n", this.nome, p1.nome);
        }
        else if(this.pai.pai == p1.pai.pai || this.mae.mae == p1.mae.mae){
            System.out.printf("%s é primo de %s\n", this.nome, p1.nome);
        }
        else if(this.pai.pai == p1 || this.mae.mae == p1){
            System.out.printf("%s é neto de %s\n",this.nome, p1.nome);
        }
        else if(this == p1.pai.pai || this == p1.mae.mae){
            System.out.printf("%s é avô de %s\n", this.nome, p1.nome);
        }
        else if(this.pai.pai.pai == p1 || this.mae.mae.mae == p1){
            System.out.printf("%s é bisneto de %s\n", this.nome, p1.nome);
        }
        else if(this == p1.pai.pai.pai || this == p1.mae.mae.mae){
            System.out.printf("%S é bisavô de %s\n", this.nome, p1.nome);
        }
        else{
            System.out.printf("%s e %s não tem parentesco\n", this.nome, p1.nome);
        }
    }
}

