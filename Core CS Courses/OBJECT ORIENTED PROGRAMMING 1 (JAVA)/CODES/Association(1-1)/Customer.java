import java.lang.*;

public class Customer
{
	private int phnnb;
	private Account account;
	public Customer()
	{
		System.out.println("Empty for Customer");
	}
	public Customer(int phnnb,Account account)
	{
		System.out.println("Para for Customer");
		this.phnnb=phnnb;
		this.account=account;
	}
	public void setphnnb(int phnnb)
	{
		this.phnnb=phnnb;
	}
	public void setaccount(Account account)
	{
		this.account=account;
	}
	public int getphnnb()
	{
		return phnnb;
	}
	public Account getaccount()
	{
		return account;
	}
	public void details()
	{
		System.out.println("Customer Phonenb "+phnnb);
		account.details();
	}
}