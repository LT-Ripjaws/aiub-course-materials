package Classes;
import java.lang.*;
import Interfaces.*;

public class fixedaccount extends Account
{
	private int tenureYear;
	
	public void settenureyear(int tenureYear)
	{
		this.tenureYear=tenureYear;
	}
	public int gettenureyear()
	{
		return tenureYear;
	}
	
	public void details()
	{
		super.details();
		System.out.println("Account tenure Year "+tenureYear);
	}
}