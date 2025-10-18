package Classes;
import java.lang.*;
import Interfaces.*;

public class customer implements IAccountOperation
{
	Account accounts[];
	
	public customer()
	{
		System.out.println("Empty Customer");
	}
	
	public customer(int sizeofarray)
	{
		accounts = new Account[sizeofarray];
	}
	
	
	public void addAccount(Account a)
	{
		int flag=0;
		for(int i=0;i<accounts.length;i++)
		{
			if(accounts[i]==null)
			{
				accounts[i]=a;
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			System.out.println("Account Added");
		}
		else
		{
			System.out.println("Account Addition Failed");
		}
	}
	
	public void removeAccount(Account a)
	{
		int flag=0;
		for(int i=0;i<accounts.length;i++)
		{
			if (accounts[i]==a)
			{
				accounts[i]=null;
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			System.out.println("---------------Remove-------");
			System.out.println("Remove Account Done");
		}
		else
		{
			System.out.println("Cannot Remove");
		}
	}
	
	public void showAllAccounts()
	{
		for(int i=0;i<accounts.length;i++)
		{
			if(accounts[i]!=null)
			{
				System.out.println("------------Details--------------");
				accounts[i].details();
				System.out.println("------------------");
			}
			else
			{
				System.out.println("index null");
			}
		}
	}
	
}