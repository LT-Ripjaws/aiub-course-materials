import java.lang.*;

public class Account 
{
	private int accNo;
	public double balance;
	
	public Account(int accNo,double balance)
	{
		this.accNo=accNo;
		this.balance=balance;
	}
	
	public void display()
	{
		System.out.println("Acc No: "+accNo);
		System.out.println("Acc No: "+balance);
	}
	
	public void withdraw(double amount)
	{
		if (balance>amount && amount>0)
		{
			balance=balance-amount;
		}
		else
		{
			System.out.println("Transaction failed!!");
		}
	}
	
}