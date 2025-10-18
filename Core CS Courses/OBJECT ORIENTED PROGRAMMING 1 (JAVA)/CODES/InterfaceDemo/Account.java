import java.lang.*;

public abstract class Account
{
	public int accountNumber;
	public String accountHolderName;
	public double balance;
	
	public void setaccountNumber(int accountNumber)
	{
		this.accountNumber=accountNumber;
	}
	
	public void setaccountHolderName(String accountHolderName)
	{
		this.accountHolderName=accountHolderName;
	}
	
	public void setbalance(double balance)
	{
		this.balance=balance;
	}
	
	public int getaccountNumber()
	{
		return accountNumber;
	}
	
	public String getaccountHolderName()
	{
		return accountHolderName;
	}
	
	public double getbalance()
	{
		return balance;
	}
	
	public void details()
	{
		System.out.println("Account Number "+accountNumber);
		System.out.println("Account Holder Name "+accountHolderName);
		System.out.println("Account Balance "+balance);
	}
}