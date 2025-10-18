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
		
		
		//InputMismatchException
		/*
		System.out.print("Please Enter an Integer: ");
		ed.x = sc.nextInt();
		System.out.print("Please Enter an Integer: ");
		ed.y = sc.nextInt();
		
		System.out.println(ed.x+ed.y);
		
		
		*/
		
		
		//ArithmeticException
		/*
		System.out.print("Please Enter an Integer: ");
		ed.x = sc.nextInt();
		System.out.print("Please Enter an Integer: ");
		ed.y = sc.nextInt();
		
		System.out.println(ed.x/ed.y);
		*/
		
		//NullPointerException
	
		/*
		System.out.println(ed.s.length());
		System.out.println(ed.s.isEmpty());
		
		*/
		
		//NumberFormatException
		
		/*
		System.out.print("Please Enter a String: ");
		ed.s = sc.next();
		int i = Integer.parseInt(ed.s);
		System.out.println(i);
		
		*/
		
		//ArrayIndexOutOfBoundsException
		/*
		int a[] = new int[]{10,20,30};
		
		for(int i=0; i<=3; i++)
		{
			System.out.println(a[i]);
		}
		*/
		
		
		System.out.println("End");
		
		
	}
}