import java.lang.*;

public class Start
{
	public static void main(String[] args)
	{
		customer c1=new customer(4);
		
		savingaccount sa1=new savingaccount();
		sa1.setaccountNumber(1111);
		sa1.setaccountHolderName("Shakib");
		sa1.setbalance(78000000);
		sa1.setinterestrate(10.5);
		
		savingaccount sa2=new savingaccount();
		sa2.setaccountNumber(2222);
		sa2.setaccountHolderName("Tamim");
		sa2.setbalance(800000);
		sa2.setinterestrate(8);
		
		fixedaccount fa1=new fixedaccount();
		fa1.setaccountNumber(333);
		fa1.setaccountHolderName("Musfiq");
		fa1.setbalance(670000);
		fa1.settenureyear(7);
		
		fixedaccount fa2=new fixedaccount();
		fa2.setaccountNumber(444);
		fa2.setaccountHolderName("Mahi");
		fa2.setbalance(68000);
		fa2.settenureyear(6);
		
		c1.addAccount(sa1);
		c1.addAccount(sa2);
		c1.addAccount(fa1);
		c1.addAccount(fa2);
		
		c1.showAllAccounts();
		
		c1.removeAccount(sa2);
		
		c1.showAllAccounts();
	}
}