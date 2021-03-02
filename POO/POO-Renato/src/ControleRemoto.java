public class ControleRemoto {
    private Televisao tv;

    ControleRemoto(){
        tv = new Televisao();
    }

    public void trocarCanal(int canal){
        this.tv.trocarCanal(canal);
        this.tv.consultar();
    }
    public  void aumentarVolume(){
        this.tv.aumetaVolume();
        this.tv.consultar();
    }
    public void diminuirVolume(){
        this.tv.diminuiVolume();
        this.tv.consultar();
    }

}
class TesteControle{
    public static void main(String[] args) {
        ControleRemoto c = new ControleRemoto();
        c.aumentarVolume();
        c.diminuirVolume();
        c.trocarCanal(8);
        c.trocarCanal(45);
        c.trocarCanal(2);
        c.aumentarVolume();
        c.aumentarVolume();
        c.aumentarVolume();
        c.aumentarVolume();
        c.aumentarVolume();
        c.aumentarVolume();
        c.aumentarVolume();
        c.aumentarVolume();
    }
}
