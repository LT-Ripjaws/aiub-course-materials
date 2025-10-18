import java.lang.*;
import java.util.Random;

public class RandomDemo
{
	public static void main(String args[])
	{
		Random rd = new Random();
		
		for(int i=0; i<5; i++)
		{
			int x = rd.nextInt(89999999)+10000000;
			//int x = rd.nextInt(100) * (-1);
			//int x = (rd.nextInt(50) * 2)+1;
			
			System.out.println(x);
		}
	}
}






