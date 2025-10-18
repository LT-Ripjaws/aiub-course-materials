import java.lang.*;

public class FinalAttributeDemo
{
	final int a=111;
	
	public FinalAttributeDemo()
	{
	//	a=10;
	}
	public FinalAttributeDemo(int a)
	{
		//this();
		//this.a = a;
	}
	
	//public void setA(int a){this.a = a;}
	public int getA(){return a;}
}