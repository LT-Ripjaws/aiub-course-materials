import java.lang.*;

public class fixedaccount extends Account
{
	public double fixedBalance;
	
	public fixedaccount(int accNo,double balance,double fixedBalance)
	{
		super(accNo,balance);
		this.fixedBalance=fixedBalance;
	}
	
	public void display()
	{
		super.display();
		System.out.println("Fixed ammount: "+fixedBalance);
	}
	
	public void withdraw (double amount)
	{
		if(balance>amount && amount>0 && (balance-amount)>fixedBalance)
		{
			balance= balance-amount;
		}
		else
		{
			System.out.println("Transaction failed");
		}
	}
}