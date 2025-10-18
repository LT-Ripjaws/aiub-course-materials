import java.lang.*;
import java.io.*;

//readLine() is a method of BufferedReader
//So, we need an object of BufferedReader class to call that method.
//But, to create an object of BufferedReader, we need an object of InputStreamReader
//The parameterized constructor of InputStreamReader takes "System.in" as its parameter

public class StringInput
{
	public static void main(String args[]) throws IOException
	{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader bfr = new BufferedReader(isr);
		
		try
		{
			System.out.print("Enter a String: ");
			String s = bfr.readLine();
			System.out.println(s);
		}
		catch(IOException ioe)
		{
			System.out.println("Something is Wrong");
		}
	}
}
