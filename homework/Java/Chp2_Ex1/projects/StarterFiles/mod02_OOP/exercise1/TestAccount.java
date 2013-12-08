public class TestAccount {

  public static void main(String[] args) {

    Account acct = new Account(100.0);

    acct.deposit(50.0);

    acct.withdraw(147.0);

    // Print out the final account balance
    System.out.println("The final balance is " + acct.getBalance());
  }
}
