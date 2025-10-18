import java.lang.*;
import java.util.Scanner;

public class Start
{
	public static void main(String args[])
	{
		System.out.println("Start");
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		try
		{
			if(s.length() > 5)
			{
				System.out.println("Invalid String");
				throw new MyException();
			}
			else
			{
				System.out.println("Valid String");
			}
		}
		catch(MyException me)
		{
			System.out.println(me.getMessage());
			me.printStackTrace();
		}
		System.out.println("End");
	}
}