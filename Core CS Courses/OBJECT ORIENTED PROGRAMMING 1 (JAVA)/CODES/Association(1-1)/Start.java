import java.lang.*;

public class Start
{
	public static void main(String[] args)
	{
		Account a1=new Account(6238,"personal",8797686);
		Customer c1=new Customer(9167575,a1);
		c1.details();
	}
	
}