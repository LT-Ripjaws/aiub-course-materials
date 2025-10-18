using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Labtask1
{
    struct student
    {
        public string firstName, lastName, addressLine1, addressLine2, birthDate, City, StateProvince, Country;
        public int ZipPostal;

        public student(string fname, string lname, string aline1, string aline2, string bdate, string city, string state, string country, int zip)
        {
            firstName = fname;
            lastName = lname;
            addressLine1 = aline1;
            addressLine2 = aline2;
            birthDate = bdate;
            City = city;
            StateProvince = state;
            Country = country;
            ZipPostal = zip;
        }

       
        public void showInfo()
        {
            Console.WriteLine("\nThe Student info is=\nFirst Name: " + firstName + "\nLast Name: " + lastName +
                "\nBirthdate: " + birthDate + "\nAddress Line 1: " + addressLine1 + "\nAddress Line 2: " + addressLine2 +
                "\nCountry: " + Country + "\nCity: " + City + "\nState/Province: " + StateProvince + "\nZip/Postal: " + ZipPostal);

        }
    }

    class Area
    {
        public double CircleArea(double r)
        {
            return 3.142 * r * r;
        }
        public double RectangularArea(double h, double w)
        {

            return h * w;
        }

        public double TriangleArea(double h, double b)
        {
            return 0.5 * h * b;

        }
    }
    internal class Program
    {

        
        static void Main(string[] args)
        {
            string firstName, lastName, addressLine1, addressLine2, birthDate, City, StateProvince, Country;
            int ZipPostal;

            //1.C# console application to output values of student variables.
            /*firstName = "Shuvro";
            lastName = "Roy";
            addressLine1 = "123 Street";
            addressLine2 = "Null";
            City = "Dhaka";
            birthDate = "10-10-10";
            StateProvince = "Dhaka";
            ZipPostal = 1221;
            Country = "Bangladesh";*/

            //2. Modified problem 1 to use Console.Readline()
            /*Console.WriteLine("What is the First Name?");
            firstName = Console.ReadLine();
            Console.WriteLine("\nWhat is the Last Name?");
            lastName = Console.ReadLine();
            Console.WriteLine("\nWhat is the birth date?");
            birthDate = Console.ReadLine();
            Console.WriteLine("\nWhat is the Country Name?");
            Country = Console.ReadLine();
            Console.WriteLine("\nWhat is the State/Province Name?");
            StateProvince = Console.ReadLine();
            Console.WriteLine("\nWhat is the City Name?");
            City = Console.ReadLine();
            Console.WriteLine("\nWhat is the 1st Address?");
            addressLine1 = Console.ReadLine();
            Console.WriteLine("\nWhat is the 2nd Address?");
            addressLine2 = Console.ReadLine();
            Console.WriteLine("\nWhat is the Zip/Postal?");
            ZipPostal = Convert.ToInt32(Console.ReadLine());
            */


            //used by both no.1 and no.2
            /*Console.WriteLine("\nThe Student info is=\nFirst Name: " + firstName + "\nLast Name: " + lastName +
                "\nBirthdate: " + birthDate + "\nAddress Line 1: " + addressLine1 + "\nAddress Line 2: " + addressLine2 +
                "\nCountry: " + Country + "\nCity: " + City + "\nState/Province: " + StateProvince + "\nZip/Postal: " + ZipPostal);

            */

            //3. Struct to represent students.
            //student s1 = new student(firstName,lastName,addressLine1,addressLine2,birthDate,City,StateProvince,Country,ZipPostal);
            //s1.showInfo();



            //4.C# program that utilises functions to find area of circle,rectangle and triangle.
            Console.WriteLine("Enter Radius for Circle Area");
            double radius = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Enter height and width for Rectangle Area respectively");
            double height = Convert.ToDouble(Console.ReadLine());
            double width = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Enter height and base for Triangle Area");
            double height2 = Convert.ToDouble(Console.ReadLine());
            double base2 = Convert.ToDouble(Console.ReadLine());

            Area a1 = new Area();
            Console.WriteLine("Area of Circle: "+a1.CircleArea(radius));
            Console.WriteLine("Area of Rectangle: "+a1.RectangularArea(height, width));
            Console.WriteLine("Area of Triangle: "+a1.TriangleArea(height2, base2));



            Console.ReadKey();       
        }
    }
}
