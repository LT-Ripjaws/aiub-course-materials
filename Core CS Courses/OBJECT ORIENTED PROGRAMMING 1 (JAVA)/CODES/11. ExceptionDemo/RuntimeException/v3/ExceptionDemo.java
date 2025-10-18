import java.lang.*;
import java.util.*;

public class ExceptionDemo
{
	private int x, y;
	private String s;
	public static void main(String args[])
	{
		System.out.println("Start");
		Scanner sc = new Scanner(System.in);
		ExceptionDemo ed = new ExceptionDemo();
		
		
		//InputMismatchException or ArithmeticException
		
		try
		{
			System.out.print("Please Enter an Integer: ");
			ed.x = sc.nextInt();
			System.out.print("Please Enter an Integer: ");
			ed.y = sc.nextInt();
		
			System.out.println(ed.x+ed.y);
		
			System.out.println(ed.x/ed.y);
		}
		catch(ArithmeticException ae)
		{
			System.out.println("ArithmeticException occured");
			ae.printStackTrace();
			ed.y = 1;
		}
		catch(InputMismatchException ime)
		{
			System.out.println("InputMismatchException occured");
			ed.x = 1;
			ed.y = 1;
		}
		
		
		//NullPointerException or NumberFormatException
	
		
		try
		{
			if(ed.x % 2 == 0)
			{
				System.out.print("Please Enter a String: ");
				ed.s = sc.next();
				int i = Integer.parseInt(ed.s);
				System.out.println(i);
			}			
			System.out.println(ed.s.length());
			System.out.println(ed.s.isEmpty());
		}
		catch(NullPointerException npe)
		{
			System.out.println("NullPointerException occured");
		}
		catch(NumberFormatException nfe)
		{
			System.out.println("NumberFormatException occured");
		}
		catch(Exception e)
		{
			//System.out.println("Exception occured " + e.getMessage());
			e.printStackTrace();
		}
		
		
		//ArrayIndexOutOfBoundsException
		/*
		int a[] = new int[]{10,20,30};
		
		for(int i=0; i<=3; i++)
		{
			try
			{
				System.out.println(a[i]);
			}
			catch(ArrayIndexOutOfBoundsException aie)
			{
				System.out.println("ArrayIndexOutOfBoundsException occured");
			}
		}
		*/
		
		System.out.println("End");
		
		
	}
}

/*

InputMismatchException		-> 	null
ArithmeticException			->	/ by zero
NullPointerException 			->	null
NumberFormatException			->	For input string "12gf22"
ArrayIndexOutOfBoundsException->	3 (The number of index for which the exception has occured)

*/







