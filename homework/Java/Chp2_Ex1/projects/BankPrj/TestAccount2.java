public class TestAccount2
{
	public static void main(String[] args)
	{
		Account acct = new Account(100.0);
		acct.balance = acct.balance + 47.0;
		acct.balance = acct.balance - 150;
		System.out.println("Final account balace " + acct.balance);
	}
}