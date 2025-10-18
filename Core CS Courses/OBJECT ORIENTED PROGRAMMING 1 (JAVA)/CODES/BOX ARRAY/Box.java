import java.lang.*;

public class Box
{
	double length;
	double width;
	double heigth;
	
	public Box(double length,double width,double heigth)
	{
		System.out.println("Parameterized BOX");
		this.length=length;
		this.width=width;
		this.heigth=heigth;
	}
	
	public Box()
	{
		System.out.println("Empty box");
	}
	public void setlength(double l)
	{
		length=l;
	}
	
	public void setwidth(double w)
	{
		width=w;
	}
	
	public void setheigth(double h)
	{
		heigth=h;
	}
	
	public double getlength()
	{
		return length;
	}
	
	public double getwidth()
	{
		return width;
	}
	
	public double getheigth()
	{
		return heigth;
	}
	public void details()
	{
		System.out.println("Heigth "+this.heigth+"\n"+"Width "+this.width+"\n"+"Length "+this.length);
	}
	public static void main(String[] args)
	{
		Box b[]= new Box[6];
		
	    Box b1=new Box();
		Box b2=new Box(1.00,4.00,5.00);
		Box b3=new Box();
		b3.setheigth(10);
		b3.setwidth(20);
		b3.setlength(30);
		
		b[0]=b2;
		b[2]=b1;
		b[4]=b3;
		for(int i=1;i<3;i++)
		{
			b[i]=new Box(50,60,70);
		}
		for(int i=0;i<b.length;i++)
		{
			if(b[i] != null)
			{
				b[i].details();
			}
			else
			{
				System.out.println("Index empty");
			}
		}
		
		
	}
	
	
	
	
	
	
	
}