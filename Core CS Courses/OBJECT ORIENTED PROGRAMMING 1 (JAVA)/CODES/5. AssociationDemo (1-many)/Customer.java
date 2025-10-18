import java.lang.*;

public class Customer
{
	private String phnNumber;
	Account accounts[];
	
	public Customer()
	{
		
	}
	public Customer(String phnNumber, int sizeOfArray)
	{
		this.phnNumber = phnNumber;
		accounts = new Account[sizeOfArray];
	}
	
	public void setPhnNumber(String phnNumber)
	{
		this.phnNumber = phnNumber;
	}
	public String getPhnNumber(){return phnNumber;}
	
	public void showAllAccounts()
	{
		for(int i=0; i<accounts.length; i++)
		{
			if(accounts[i] != null)
			{
				System.out.println("--------------");
				System.out.println("AccountHolderName of Account["+ i + "]: "+accounts[i].getAccountHolderName());
				System.out.println("AccountNumber of Account["+ i + "]: "+accounts[i].getAccountNumber());
				System.out.println("Balance of Account["+ i + "]: "+accounts[i].getBalance());
				System.out.println();
			}
		}
	}
	
	public void insertAccount(Account a)
	{
		int flag = 0;
		for(int i=0; i<accounts.length; i++)
		{
			if(accounts[i] == null)
			{
				accounts[i] = a;
				flag = 1;
				break;
			}
		}
		if(flag == 1){System.out.println("----Inserted----");}
		else {System.out.println("----CanNot Insert----");}
	}
	
	
	public void removeAccount(Account a)
	{
		int flag = 0;
		for(int i=0; i<accounts.length; i++)
		{
			if(accounts[i] == a)
			{
				accounts[i] = null;
				flag = 1;
				break;
			}
		}
		if(flag == 1){System.out.println("----Removed----");}
		else {System.out.println("----CanNot Remove----");}
	}
	
	
	
	
	
	
	
	
	
	
}