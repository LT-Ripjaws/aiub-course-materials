import java.lang.*;

public class customer
{
	private String cID;
	private Account acc[];
	
	public customer(String cID,int noAcc)
	{
		this.cID=cID;
		acc=new Account[noAcc];
	}
	
	public void addAccount(Account a)
	{
		int flag=0;
		for(int i=0;i<acc.length;i++)
		{
			if(acc[i]==null)
			{
				acc[i]= a;
				flag=1;
				break;
			}
		}
		if (flag==1)
		{
			System.out.println("Account added");
		}
		else
		{
			System.out.println("Account failed");
		}
	}
	
	public void displayallaccount()
	{
		for(int i=0;i<acc.length;i++)
		{
			if(acc[i]!=null)
			{
				acc[i].display();
			}
			else{
				System.out.println("Index Null");
			}
		}
	}
	
	public void perfromwithdraw(Account a,double amount)
	{
		int flag=0;
		for(int i=0;i<acc.length;i++)
		{
			if(acc[i]==a)
			{
				acc[i].withdraw(amount);
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			System.out.println("Transaction Sucessfully done");
		}
		else
		{
			System.out.println("Transaction failed!!!!!!");
		}
		System.out.println("Withdraw Amount "+amount);
	}
	
	
	
	
	
}