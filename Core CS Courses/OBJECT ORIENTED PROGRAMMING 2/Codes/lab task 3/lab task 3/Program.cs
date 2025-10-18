using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static lab_task_3.Contact;

namespace lab_task_3
{
    //task number 1
    public class Course
    {
        private string courseName;
        private string courseCode;
        private int courseCredit;

        public string CourseName
        {
            get { return courseName; }
            set { courseName = value; }
        }

        public string CourseCode
        {
            get { return courseCode; }
            set { courseCode = value; }
        }

        public int CourseCredit
        {
            get { return courseCredit; }
            set { courseCredit = value; }
        }

        public Course()
        {
            Console.WriteLine("User defined");
        }

        public Course(string courseName, string courseCode, int courseCredit)
        {
            this.courseName = courseName;
            this.courseCode = courseCode;
            this.courseCredit = courseCredit;
        }

        public void ShowCourseInfo()
        {
            Console.WriteLine($"Course Name: {courseName}, Course Code: {courseCode}, Course Credit: {courseCredit}");
        }
    }

    public class Book
    {
        private string bookName;
        private string bookAuthor;
        private string bookId;
        private string bookType;
        private int bookCopy;

        public static int bookCounter;

        public string BookName
        {
            get { return bookName; }
            set { bookName = value; }
        }

        public string BookAuthor
        {
            get { return bookAuthor; }
            set { bookAuthor = value; }
        }

        public string BookId
        {
            get { return bookId; }
            set { bookId = value; }
        }

        public string BookType
        {
            get { return bookType; }
            set { bookType = value; }
        }

        public int BookCopy
        {
            get { return bookCopy; }
            set { bookCopy = value; }
        }

        static Book()
        {
            bookCounter = 0;
        }

        public Book()
        {
            Console.WriteLine("User defined");
        }

        public Book(string bookName, string bookAuthor, string bookId, string bookType, int bookCopy)
        {
            this.bookName = bookName;
            this.bookAuthor = bookAuthor;
            this.bookId = bookId;
            this.bookType = bookType;
            this.bookCopy = bookCopy;
            bookCounter++;
        }

        public void ShowInfo()
        {
            Console.WriteLine($"Book Name: {bookName}, Book Author: {bookAuthor}, Book ID: {bookId}, Book Type: {bookType}, Book Copy: {bookCopy}");
        }

        public void AddBookCopy(int x)
        {
            bookCopy += x;
        }
    }

    public class Contact
    {
        private string personName;
        private string personID;
        private int age;
        private string mobileNumber;
        private char gender;

        public string PersonName
        {
            get { return personName; }
            set { personName = value; }
        }

        public string PersonID
        {
            get { return personID; }
            set { personID = value; }
        }

        public int Age
        {
            get { return age; }
            set { age = value; }
        }

        public string MobileNumber
        {
            get { return mobileNumber; }
            set { mobileNumber = value; }
        }

        public char Gender
        {
            get { return gender; }
            set { gender = value; }
        }

        public Contact()
        {
           Console.WriteLine("User Defined");
        }

        public Contact(string personName, string personID, int age, string mobileNumber, char gender)
        {
            this.personName = personName;
            this.personID = personID;
            this.age = age;
            this.mobileNumber = mobileNumber;
            this.gender = gender;
        }

        public void ShowPersonInfo()
        {
            Console.WriteLine($"Name: {personName}, ID: {personID}, Age: {age}, Mobile Number: {mobileNumber}, Gender: {gender}");
        }

        public void DetectMobileOperator()
        {
            string operatorName = "Unknown";
            if (mobileNumber.StartsWith("017"))
            {
                operatorName = "GP";
            }
            else if (mobileNumber.StartsWith("018"))
            {
                operatorName = "Robi";
            }
            else if (mobileNumber.StartsWith("016"))
            {
                operatorName = "Airtel";
            }
            else if (mobileNumber.StartsWith("015"))
            {
                operatorName = "Teletalk";
            }
            else if (mobileNumber.StartsWith("019"))
            {
                operatorName = "Banglalink";
            }
            Console.WriteLine($"Mobile Operator: {operatorName}");
        }






        //Task number 2
        public class Vehicle
        {
            private string vehicleName;
            private string vehicleId;
            public static int vehicleCount;

            public string VehicleName
            {
                get { return vehicleName; }
                set { vehicleName = value; }
            }

            public string VehicleId
            {
                get { return vehicleId; }
                set { vehicleId = value; }
            }

            static Vehicle()
            {
                vehicleCount = 0;
            }

            public Vehicle()
            {
                vehicleName = "Unknown Vehicle";
                vehicleId = "Unknown ID";
                vehicleCount++;
            }

            public Vehicle(string vehicleName, string vehicleId)
            {
                this.vehicleName = vehicleName;
                this.vehicleId = vehicleId;
                vehicleCount++;
            }

            public virtual void Status()
            {
                Console.WriteLine("Vehicle is operational.");
            }

            public void ShowInfo()
            {
                Console.WriteLine($"Vehicle Name: {vehicleName}, Vehicle ID: {vehicleId}");
            }
        }

        public class Motorbike : Vehicle
        {
            public Motorbike() : base("Motorbike", "MB-001") { }

            public override void Status()
            {
                Console.WriteLine("Motorbike is ready to ride.");
            }
        }

        public class Truck : Vehicle
        {
            public Truck() : base("Truck", "TR-001") { }

            public override void Status()
            {
                Console.WriteLine("Truck is ready for transportation.");
            }
        }

        public class Car : Vehicle
        {
            public Car() : base("Car", "CR-001") { }

            public override void Status()
            {
                Console.WriteLine("Car is ready for a drive.");
            }
        }

        public class Saloon : Vehicle
        {
            public Saloon() : base("Saloon", "SL-001") { }

            public override void Status()
            {
                Console.WriteLine("Saloon is ready for a smooth ride.");
            }
        }

        public class MPV : Vehicle
        {
            public MPV() : base("MPV", "MPV-001") { }

            public override void Status()
            {
                Console.WriteLine("MPV is ready for a family trip.");
            }
        }


    }
    internal class Program
    {
        static void Main(string[] args)
        {

            //task number 1
            //Course C1 = new Course();
            //Course C2 = new Course("English","2AE4",3);
            //C2.ShowCourseInfo();


            //Book B1 = new Book();
            //Book B2 = new Book("Goosebumps","RL STINE","AF23","Horror",1);
            //B2.ShowInfo();

            //Contact contact = new Contact();
            //Contact contact1 = new Contact("Sadat","22-342-2",22,"0179128xxx",'M');
            //contact1.ShowPersonInfo();
            //contact1.DetectMobileOperator();

            //task number 2
            Vehicle obj1 = new Motorbike();
            Vehicle obj2 = new Truck();
            Vehicle obj3 = new Car();
            Vehicle obj4 = new Saloon();
            Vehicle obj5 = new MPV();

            obj1.ShowInfo();
            obj1.Status();

            obj2.ShowInfo();
            obj2.Status();

            obj3.ShowInfo();
            obj3.Status();

            obj4.ShowInfo();
            obj4.Status();

            obj5.ShowInfo();
            obj5.Status();

            Console.WriteLine($"Total number of vehicles: {Vehicle.vehicleCount}");


            Console.ReadKey();
        }
    }
}
