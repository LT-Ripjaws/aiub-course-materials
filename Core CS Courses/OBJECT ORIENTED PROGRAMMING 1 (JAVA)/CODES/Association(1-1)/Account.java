import java.lang.*;

public class Account
{
	private int accnb;
	private String acctype;
	private double balance;
	public Account()
	{
		System.out.println("Empty for Account");
	}
	public Account(int accnb,String acctype,double balance)
	{
		System.out.println("para for Account");
		this.accnb=accnb;
		this.acctype=acctype;
		this.balance=balance;
	}
	public void setaccnb(int accnb)
	{
		this.accnb=accnb;
	}
	public void setacctype(String acctype)
	{
		this.acctype=acctype;
	}
	public void setbalance(double balance)
	{
		this.balance=balance;
	}
	public int getaccnb()
	{
		return accnb;
	}
	public String getacctype()
	{
		return acctype;
	}
	public double getbalance()
	{
		return balance;
	}
	public void details()
	{
		System.out.println("Account Number: "+accnb);
		System.out.println("Account Type: "+acctype);
		System.out.println("Account balance: "+balance);
	}
}