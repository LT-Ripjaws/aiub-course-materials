import java.lang.*;

public class savingaccount extends Account
{
	private int tyear;
	
	public savingaccount(int accNo,double balance,int tyear)
	{
		super(accNo,balance);
		this.tyear=tyear;
	}
	
	public void display()
	{
		super.display();
		System.out.println("Something year"+tyear);
	}
	
	public void withdraw(double amount)
	{
		if(balance>amount && amount>0 && tyear>=2)
		{
			balance=balance-amount;
		}
		else
		{
			System.out.println("Transaction failed!!");
		}
	}
}