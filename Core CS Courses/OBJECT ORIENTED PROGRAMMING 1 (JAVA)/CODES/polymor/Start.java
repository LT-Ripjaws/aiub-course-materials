import java.lang.*;

public class Start
{
	public static void main(String[] args)
	{
		customer c1=new customer("C-01",3);
		
		Account a1=new savingaccount(123,50000,6);
		Account a2=new fixedaccount(456,250000,500);
		
		c1.addAccount(a1);
		c1.addAccount(a2);
		
		c1.displayallaccount();
		
		c1.perfromwithdraw(a2,2500);
		
		
		
	}
}