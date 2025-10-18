import java.lang.*;
public class Start
{
	public static void main(String args[])
	{
		FinalAttributeDemo fad1 = new FinalAttributeDemo();
		//fad.a = 100;
		System.out.println(fad1.getA());
		FinalAttributeDemo fad2 = new FinalAttributeDemo(20);
		System.out.println(fad2.getA());
		
	}
}