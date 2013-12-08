public class Account {

  private double balance;

  public Account(double initBalance) {
    balance = initBalance;
  }
  public void deposit(double amt)
  {
  	balance=balance+amt;
  }
  public void withdraw(double amt)
  {
  	if (amt<=balance)
  		balance=balance-amt;
  }
  public double getBalance()
  {
  	return balance;
  }
}