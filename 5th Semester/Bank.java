import java.util.Scanner;

class Bank_Account {
    String accountNumber;
    double balance;

    // Constructor
    Bank_Account(String accountNumber, double balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    // Deposit method
    void deposit(double amount) {
        balance = balance + amount;
        System.out.println("Deposited: " + amount);
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount <= balance) {
            balance = balance - amount;
            System.out.println("Withdrawn: " + amount);
        } else {
            System.out.println("Insufficient Balance!");
        }
    }

    // Display account information
    void display() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Balance: " + balance);
    }
}

public class Bank {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // User input
        System.out.print("Enter Account Number: ");
        String accountNumber = sc.nextLine();

        System.out.print("Enter Initial Balance: ");
        double balance = sc.nextDouble();

        // Create object
        Bank_Account account1 = new Bank_Account(accountNumber, balance);

        System.out.println("\nInitial Account Details:");
        account1.display();

        // Deposit
        System.out.print("\nEnter Deposit Amount: ");
        double depositAmount = sc.nextDouble();
        account1.deposit(depositAmount);

        // Withdraw
        System.out.print("Enter Withdraw Amount: ");
        double withdrawAmount = sc.nextDouble();
        account1.withdraw(withdrawAmount);

        System.out.println("\nUpdated Account :");
        account1.display();

        sc.close();
    }
}