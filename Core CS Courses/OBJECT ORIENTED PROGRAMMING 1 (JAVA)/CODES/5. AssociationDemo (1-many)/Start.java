import java.lang.*;

public class Start
{
	public static void main(String args[])
	{
		Customer c1 = new Customer("+880123456678", 5);
		
		Account a1 = new Account();
		a1.setAccountHolderName("OOP1 G");
		a1.setAccountNumber(11111111);
		a1.setBalance(2000.0);
		
		Account a2 = new Account();
		a2.setAccountHolderName("OOP1 C");
		a2.setAccountNumber(11111112);
		a2.setBalance(2500.0);
		
		Account a3 = new Account();
		a3.setAccountHolderName("OOP2 G");
		a3.setAccountNumber(11111113);
		a3.setBalance(2000.0);
		
		Account a4 = new Account();
		a4.setAccountHolderName("OOP2 I");
		a4.setAccountNumber(11111114);
		a4.setBalance(2500.0);
		
		Account a5 = new Account();
		a5.setAccountHolderName("OOP1 G");
		a5.setAccountNumber(11111115);
		a5.setBalance(2000.0);
		
		Account a6 = new Account();
		a6.setAccountHolderName("OOP1 C");
		a6.setAccountNumber(11111116);
		a6.setBalance(2500.0);
		
		
		c1.insertAccount(a1);
		c1.insertAccount(a2);
		
		c1.insertAccount(a3);
		c1.insertAccount(a4);
		
		c1.insertAccount(a5);
		c1.insertAccount(a6);
		
		c1.showAllAccounts();
		
		c1.removeAccount(a2);
		
		c1.showAllAccounts();
		
		c1.removeAccount(a2);
		
		
	}
}