import java.lang.*;

public class savingaccount extends Account
{
	private double interestrate;
	
	public void setinterestrate(double interestrate)
	{
		this.interestrate=interestrate;
	}
	
	public double getinterestrate()
	{
		return interestrate;
	}
	
	public void details()
	{
		super.details();
		System.out.println("Account Interest Rate  "+interestrate);
	}
}
