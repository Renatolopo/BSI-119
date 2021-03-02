public class Televisao {
    private int canalAtual;
    private int volumeAtual;

    Televisao(){
        this.canalAtual = 1;
        this.volumeAtual = 25;
    }
    private boolean canalExiste(int canal){
        if(canal > 0 && canal <= 20){
            return true;
        }else{
            return false;
        }
    }
    private void verificaVolume(){
        if(this.volumeAtual < 0){
            this.volumeAtual = 0;
        }
        else if(this.volumeAtual > 30){
            this.volumeAtual = 30;
        }
    }
    public void aumetaVolume(){
        this.volumeAtual ++;
        this.verificaVolume();
    }
    public void diminuiVolume(){
        this.volumeAtual --;
        this.verificaVolume();
    }
    public  void trocarCanal(int canal){
        if(this.canalExiste(canal)){
            this.canalAtual = canal;
        }
    }
    public void consultar(){
        System.out.printf("Canal Atual: %d    Volume atual: %d \n", this.canalAtual, this.volumeAtual);
    }
}
