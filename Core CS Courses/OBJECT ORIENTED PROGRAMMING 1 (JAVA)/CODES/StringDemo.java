import java.lang.*;

public class StringDemo
{
	public static void main(String []args)
	{
		String s1 = "Javaa";
		String s2 = "Ja";
		String s3 = new String("Java");
		String s4 = new String("Java");
		
		System.out.println(s1.compareTo(s2));
		if(s1==s2)
		{
			System.out.println("it is eqaul");
		}
		else { System.out.println("it is not equal");}
		
		System.out.println(s1.substring(1,3));
		
	}
}