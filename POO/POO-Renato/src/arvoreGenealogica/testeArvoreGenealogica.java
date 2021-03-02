package arvoreGenealogica;

public class testeArvoreGenealogica {
    public static void main(String[] args) {
        Pessoa zuza = new Pessoa("Zuza",98);
        Pessoa vozin = new Pessoa("Germino",76,zuza,null);
        Pessoa pai = new Pessoa("Renato", 49, vozin, null);
        Pessoa jose = new Pessoa("ze lopo", 54, vozin, null);
        Pessoa glenda = new Pessoa("Glenda", 20, jose, null);
        Pessoa eu = new Pessoa("Renato jr",20,pai,null);
        Pessoa fefeu = new Pessoa("Luiz", 21, pai, null);

        eu.obterParentesco(fefeu);
        eu.obterParentesco(glenda);
        eu.obterParentesco(zuza);
        eu.obterParentesco(vozin);
        eu.obterParentesco(jose);
        eu.obterParentesco(pai);
    }
}
