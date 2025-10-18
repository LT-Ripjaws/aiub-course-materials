import java.lang.*;

public class TypeCastingDemo
{
	public static void main(String args[])
	{
		char c1='a', c2='s';
		float f1=0.0F, f2=65.0F;
		double d1=0.0, d2=75.8;
		byte b1=126, b2=125;
		short s1=254, s2=253;
		int i1=2147483646, i2=68;
		long l1=9999999999999L, l2=9999999999998L;
		
		System.out.println("Char -> Float -- Implicit/Auto/Small-To-Large Casting");
		System.out.println("Before	C1: "+c1);
		f1=c1;	//implicit type casting 
		System.out.println("After	F1: "+f1);
		System.out.println();
		
		System.out.println("Float -> Char -- Explicit/Non-Auto/Large-To-Small Casting");
		System.out.println("Before	F2: "+f2);
		c2=(char)f2;	//explicit type casting 
		System.out.println("After	C2: "+c2);
		System.out.println();
		
		System.out.println("Char -> Integer -- Implicit/Auto/Small-To-Large Casting");
		System.out.println("Before	C1: "+c1);
		i1=c1;	//implicit type casting 
		System.out.println("After	I1: "+i1);
		System.out.println();
		
		System.out.println("Integer -> Char -- Explicit/Non-Auto/Large-To-Small Casting");
		System.out.println("Before	I2: "+i2);
		c2=(char)i2;	//explicit type casting 
		System.out.println("After	C2: "+c2);
		System.out.println();
		
		System.out.println("Float -> Double -- Implicit/Auto/Small-To-Large Casting");
		System.out.println("Before	F1: "+f1);
		d1=f1;	//implicit type casting 
		System.out.println("After	D1: "+d1);
		System.out.println();
		
		System.out.println("Double -> Float -- Explicit/Non-Auto/Large-To-Small Casting");
		System.out.println("Before	D2: "+d2);
		f2=(float)d2;	//explicit type casting 
		System.out.println("After	F2: "+f2);
		System.out.println();
		
		System.out.println("Int -> Long -- Implicit/Auto/Small-To-Large Casting");
		System.out.println("Before	I1: "+i1);
		l1= i1;	//implicit type casting 
		System.out.println("After	L1: "+l1);
		System.out.println();
		
		System.out.println("Long -> Int -- Explicit/Non-Auto/Large-To-Small Casting");
		System.out.println("Before	L2: "+l2);
		i2= (int) l2;	//explicit type casting 
		System.out.println("After	I2: "+i2);
		System.out.println();
		
		System.out.println("Int -> Double -- Implicit/Auto/Small-To-Large Casting");
		System.out.println("Before	I1: "+i1);
		d1=i1;	//implicit type casting 
		System.out.println("After	D1: "+d1);
		System.out.println();
		
		System.out.println("Double -> Int -- Explicit/Non-Auto/Large-To-Small Casting");
		System.out.println("Before	D2: "+d2);
		i2= (int)d2;	//explicit type casting 
		System.out.println("After	I2: "+i2);
		System.out.println();
		
		System.out.println("Char -> Short -- Explicit/Auto/Small-To-Large Casting");
		System.out.println("Before	C1: "+c1);
		s1= (short)c1;	//explicit type casting 
		System.out.println("After	S1: "+s1);
		System.out.println();
		
		System.out.println("Short -> Char -- Explicit/Non-Auto/Large-To-Small Casting");
		System.out.println("Before	S2: "+s2);
		c2= (char)s2;	//explicit type casting 
		System.out.println("After	C2: "+c2);
		System.out.println();
	}
}