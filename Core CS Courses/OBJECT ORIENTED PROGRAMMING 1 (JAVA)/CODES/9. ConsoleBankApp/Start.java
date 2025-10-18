import java.lang.*;
import classes.*;
import interfaces.*;
import java.util.*;
import fileio.*;

public class Start
{
	public static void main(String args[])
	{
		System.out.println("Welcome to Sample Bank Application");
		boolean choice = true;
		Scanner sc = new Scanner(System.in);
		Bank b = new Bank();
		FileReadWriteDemo frwd = new FileReadWriteDemo();
		
		while(choice)
		{
			System.out.println("Here are Some Options for You: \n");
			System.out.println("	1. Employee Management");
			System.out.println("	2. Customer Management");
			System.out.println("	3. Customer Account Management");
			System.out.println("	4. Account Transactions");
			System.out.println("	5. Exit the Application\n");
			System.out.print("What do you want to do? : ");
			
			int first = sc.nextInt();
			
			switch(first)
			{
				case 1:
					
					System.out.println("You have selected Employee Management");
					System.out.println("Here are Some Options for You: \n");
					System.out.println("	1. Create New Employee");
					System.out.println("	2. Remove Existing Employee");
					System.out.println("	3. See all Employees");
					System.out.println("	4. Go Back\n");
					System.out.print("What do you want to do? : ");
					int second1 = sc.nextInt();
					
					switch(second1)
					{
						case 1:
							
							System.out.println("You have Selected to create a new Employee\n");
							System.out.print("Enter Employee Id: ");
							String empId = sc.next();
							System.out.print("Enter Employee Name: ");
							String name = sc.next();
							System.out.print("Enter Employee Salary: ");
							double salary = sc.nextDouble();
							
							Employee e = new Employee();
							e.setEmpId(empId);
							e.setName(name);
							e.setSalary(salary);
							
							b.insertEmployee(e);
							
							
							break;
							
						case 2:
							
							System.out.println("You have Selected to remove an existing Employee");
							System.out.print("Enter Employee Id: ");
							
							
							b.removeEmployee(b.getEmployee(sc.next()));
							
							break;
							
						case 3:
							
							System.out.println("You have Selected to see all Employees");
							
							b.showAllEmployees();
							
							break;
						
						case 4:
							
							System.out.println("You have Selected to Go Back");
							break;
						
						default:
							
							System.out.println("Invalid Input");
							break;
					}
					
					break;
					
				case 2:
				
					System.out.println("You have selected Customer Management");
					
					System.out.println("Here are Some Options for You: \n");
					System.out.println("	1. Create New Customer");
					System.out.println("	2. Remove Existing Customer");
					System.out.println("	3. See all Customers");
					System.out.println("	4. Go Back\n");
					System.out.print("What do you want to do? : ");
					int second2 = sc.nextInt();
					
					switch(second2)
					{
						case 1:
						
							System.out.print("Enter Customer Nid: ");
							int nid1 = sc.nextInt();
							System.out.print("Enter Customer Name: ");
							String name1 = sc.next();
							
							Customer c = new Customer();
							c.setNid(nid1);
							c.setName(name1);
							
							b.insertCustomer(c);
							break;
							
						case 2:
						
							System.out.print("Enter Customer Nid: ");
							int nid2 = sc.nextInt();
							
							b.removeCustomer(b.getCustomer(nid2));
							break;
						
						case 3:
						
							b.showAllCustomers();
							break;
						
						case 4:
						
							System.out.println("Going Back . . .");
							break;
							
						default:
						
							System.out.println("Invalid Input");
							break;
					}
					
					break;
				
				case 3:
					
					System.out.println("You have selected Customer Account Management");
					
					System.out.println("Here are Some Options for You: \n");
					System.out.println("	1. Create New Account for a Customer");
					System.out.println("	2. Remove Existing Account of a Customer");
					System.out.println("	3. See all Accounts of a Customer");
					System.out.println("	4. Go Back\n");
					System.out.print("What do you want to do? : ");
					int second3 = sc.nextInt();
					
					switch(second3)
					{
						case 1: 
						
							Account a = null;
							
							System.out.println("There are 2 types of Account: ");
							System.out.println("	1. Savings Account");
							System.out.println("	2. Fixed Account");
							System.out.println("	3. Go Back\n");
							System.out.print("What do you want to do? : ");
							
							int type = sc.nextInt();
							
							System.out.print("Enter Account Number: ");
							int an1 = sc.nextInt();
							System.out.print("Enter Opening Balance: ");
							double b1 = sc.nextDouble();
							
							if(type == 1)
							{
								System.out.print("Enter Interest Rate: ");
								double ir = sc.nextDouble();
								
								SavingsAccount sa = new SavingsAccount();
								sa.setAccountNumber(an1);
								sa.setBalance(b1);
								sa.setInterestRate(ir);
								
								a = sa;
								
							}
							else if(type == 2)
							{
								System.out.print("Enter Tenure Year: ");
								int ty = sc.nextInt();
								
								FixedAccount fa = new FixedAccount();
								fa.setAccountNumber(an1);
								fa.setBalance(b1);
								fa.setTenureYear(ty);
								
								a = fa;
							}
							else if(type == 3)
							{
								System.out.print("Going Back . . .");
							}
							else
							{
								System.out.println("Invalid Input");
							}
							if(a!=null)
							{
								System.out.print("Enter Customer Nid: ");
								int nid = sc.nextInt();
								b.getCustomer(nid).insertAccount(a);
							}
							
							break;
							
						case 2:
						
							System.out.print("Enter Customer Nid: ");
							int nid2 = sc.nextInt();
							System.out.print("Enter Account Number: ");
							int an2 = sc.nextInt();
							
							b.getCustomer(nid2).removeAccount(b.getCustomer(nid2).getAccount(an2));
							
							break;
							
						case 3:
						
							System.out.print("Enter Customer Nid: ");
							int nid3 = sc.nextInt();
							
							b.getCustomer(nid3).showAllAccounts();
							break;
							
						case 4:
						
							System.out.println("Going Back . . .");
							break;
							
						default:
						
							System.out.println("Invalid Input");
							break;
					}
					
					break;
					
				case 4:
				
					System.out.println("You have selected Account Transactions");
					System.out.println("Here are Some Options for You: \n");
					System.out.println("	1. Deposit Money");
					System.out.println("	2. Withdraw Money");
					System.out.println("	3. Transfer Money");
					System.out.println("	4. Show Transaction History");
					System.out.println("	5. Go Back\n");
					System.out.print("What do you want to do? : ");
					int second4 = sc.nextInt();
					
					switch(second4)
					{
						case 1:
							
							System.out.print("Enter Customer Nid: ");
							int nid1 = sc.nextInt();
							System.out.print("Enter Account Number: ");
							int an1 = sc.nextInt();
							System.out.print("Enter Deposit Amount: ");
							double amount1 = sc.nextDouble();
							
							b.getCustomer(nid1).getAccount(an1).deposit(amount1);
							frwd.writeInFile("$"+amount1+" Deposited in Account Number: "+an1);
							//frwd.writeInFile(t1.getId()+","+t1.getName()+","+t1.getSalary());
							break;
							
						case 2:
						
							System.out.print("Enter Customer Nid: ");
							int nid2 = sc.nextInt();
							System.out.print("Enter Account Number: ");
							int an2 = sc.nextInt();
							System.out.print("Enter Withdraw Amount: ");
							double amount2 = sc.nextDouble();
							
							b.getCustomer(nid2).getAccount(an2).withdraw(amount2);
							frwd.writeInFile("$"+amount2+" Withdrawn from Account Number: "+an2);
							break;
							
						case 3:
						
							System.out.print("Enter Sending Customer Nid: ");
							int nid3s = sc.nextInt();
							System.out.print("Enter Sending Account Number: ");
							int an3s = sc.nextInt();
							System.out.print("Enter Transfer Amount: ");
							double amount3 = sc.nextDouble();
							System.out.print("Enter Receiving Customer Nid: ");
							int nid3r = sc.nextInt();
							System.out.print("Enter Receiving Account Number: ");
							int an3r = sc.nextInt();
							
							b.getCustomer(nid3s).getAccount(an3s).transfer(b.getCustomer(nid3r).getAccount(an3r), amount3);
							frwd.writeInFile("$"+amount3+" Transferred from Account Number: "+an3s +" to Account Number "+an3r);
							break;
						
						case 4:
						
							frwd.readFromFile();
							
							break;
						
						case 5:
						
							System.out.println("You have Selected to Go Back");
							break;
							
						default:
						
							System.out.println("Invalid Input");
							break;
					}
					
					
					break;
					
				case 5:
					
					System.out.println("You have selected to exit the application");
					System.out.println("Thank you for using Sample Bank");
					choice = false;
					break;
					
				default:
				
					System.out.println("Invalid Input");
					break;
			}
		}
		
	}
}
