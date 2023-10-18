import java.util.Scanner;

class Main
{
	public static void main(String Args[])
	{
		Scanner sobj = new Scanner(System.in);
		int iChoice;
		
		while(true)
		{
			System.out.println("---------------------------------------------------------");
			System.out.println("1 : Programmer");
			System.out.println("2 : AsstManager");
			System.out.println("3 : ProjectManager");
			System.out.println("4 : TeamLeader");
			System.out.println("5 : Exit");
			System.out.println("---------------------------------------------------------");
			
			
			System.out.println("Enter the Choice : ");
			iChoice = sobj.nextInt();
			
			switch(iChoice)
			{
				case 1:
					Programmer pobj = new Programmer();
					pobj.getBasicPay();
					pobj.Calculate();
					pobj.DisplayPaySlip();
					break;
				
				case 2:
					AsstManager aobj = new AsstManager();
					aobj.getBasicPay();
					aobj.Calculate();
					aobj.DisplayPaySlip();
					break;
					
				case 3:
					ProjectManager ppobj = new ProjectManager();
					ppobj.getBasicPay();
					ppobj.Calculate();
					ppobj.DisplayPaySlip();
					break;
				
				case 4:
					TeamLeader tobj = new TeamLeader();
					tobj.getBasicPay();
					tobj.Calculate();
					tobj.DisplayPaySlip();
					break;
					
				case 5:
					return;
				
				default:
					System.out.println("Invalid Choice");
					break;
			}
		}
	}
}