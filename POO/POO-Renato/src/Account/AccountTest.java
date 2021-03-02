package Account;
import java.util.Scanner;

public class AccountTest {
    public static void main(String[] args) {
        Account account1 = new Account(50.00);
        Account account2 = new Account(-7.53);

        System.out.printf("account balance $%.2f \n",
                account1.getBalance());
        System.out.printf("account2 balance: $%.2f \n\n",
                account2.getBalance());

        Scanner input = new Scanner(System.in);
        double depositAccount;

        System.out.print("Enter deposit amount for account1: ");
        depositAccount = input.nextDouble();
        System.out.printf("\nadding %.2f to account1 balance\n\n",
                depositAccount);
        account1.credit(depositAccount);

        System.out.printf("account1 balance: $%.2f \n",
                account1.getBalance());
        System.out.printf("account2 balance: $%.2f \n",
                account2.getBalance());

        System.out.printf("Enter deposit account2: ");
        depositAccount = input.nextDouble();
        System.out.printf("\nadding %.2f to account2 balance\n",
                depositAccount);
        account2.credit(depositAccount);

        System.out.printf("account1 balance: $%.2f \n",
                account1.getBalance());
        System.out.printf("account2 balance: $%.2f \n",
                account2.getBalance());


        account1.debit(100.0);

        System.out.printf("\n\naccount1 balance: $%.2f \n",
                account1.getBalance());
        System.out.printf("account2 balance: $%.2f \n",
                account2.getBalance());
    }
}
