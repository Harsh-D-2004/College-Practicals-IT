import java.util.Scanner;

public class Employee {
	
	Scanner sobj = new Scanner(System.in);
	
	public int Id;
	public String Name;
	public String Mail_Id;
	public String Address;
	public long Mobile_No;
	public double Basic_Pay;
	
	
	
	public void getdata()
	{
		System.out.println("Enter the ID : ");
		Id = sobj.nextInt();
		System.out.println("Enter the Name of Employee : ");
		Name = sobj.next();
		System.out.println("Enter the Mail_ID : ");
		Mail_Id = sobj.next();
		System.out.println("Enter the Address : ");
		Address = sobj.next();
		System.out.println("Enter the Mobile No : ");
		Mobile_No = sobj.nextLong();
	}
	
	public void Display()
	{	
		System.out.println("-----------Personal Info-----------------");
		System.out.println();
		System.out.println("ID 	:	 " + Id);
		System.out.println("Name 	:	 " + Name);
		System.out.println("Mail ID 	:	 " + Mail_Id);
		System.out.println("Address 	:	 " + Address);
		System.out.println("Mobile No 	:	 " + Mobile_No);
	}
	

}