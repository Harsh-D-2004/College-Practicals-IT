import java.util.Scanner;

public class ProjectManager extends Employee{
	Scanner sobj = new Scanner(System.in);
	
	public double DA;
	public double HRA;
	public double PF;
	public double Club_Fund;
	public double gross_salary;
	public double net_salary;
	
	public ProjectManager()
	{	
		getdata();
		Display();
		getBasicPay();
		Calculate();
		DisplayPaySlip();
	}
	
	public void getBasicPay()
	{
		System.out.println("Enter the Basic Pay : ");
		Basic_Pay = sobj.nextInt();
	}
	
	public void Calculate()
	{
		this.DA = 0.97 * Basic_Pay;
		this.HRA = 0.10 * Basic_Pay;
		this.PF = 0.12 * Basic_Pay;
		this.Club_Fund = 0.001 * Basic_Pay;
		this.gross_salary = Basic_Pay + DA + HRA;
		this.net_salary = gross_salary - PF - Club_Fund;
	}
	
	public void DisplayPaySlip()
	{
		System.out.println("-----------------Pay Slip-----------------");
		
		System.out.println("Basic Pay 	:	 " + Basic_Pay);
		System.out.println("DA 		:	 " + this.DA);
		System.out.println("HRA 	:	 " + HRA);
		System.out.println("PF 		:	 " + PF);
		System.out.println("Club Fund 	:	 " + Club_Fund);
		System.out.println("Gross Salary  	:	 " + gross_salary);
		System.out.println("Net Salary 		:	  " + net_salary);
	}
}
