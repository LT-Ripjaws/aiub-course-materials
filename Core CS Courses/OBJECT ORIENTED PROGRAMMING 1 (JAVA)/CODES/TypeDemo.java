import java.lang.*;

public class TypeDemo
{
	public static void main(String[] args)
	{
		char c1='c';
		float f1=60.0F;
		
		System.out.println("float->char exlicit");
		System.out.println("C1"+c1);
		System.out.println("F1"+f1);
		c1=(char)f1;
		System.out.println("C1"+c1);
		System.out.println("F1"+f1);
		
	}
	
}