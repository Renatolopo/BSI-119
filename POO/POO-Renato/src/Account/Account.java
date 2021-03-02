package Account;

public class Account {
    private double balance;

    public Account(double initialBalance){
        if(initialBalance > 0.0){
            balance = initialBalance;
        }
    }
    public void credit(double amount){
        balance = balance + amount;
    }
    public double getBalance(){
        return balance;
    }
    public void debit(double val){
        if(this.balance >= val){
            this.balance -= val;
        }
        else{
            System.out.printf("Quantia de débito excedeu o saldo da conta");
        }
    }
}
