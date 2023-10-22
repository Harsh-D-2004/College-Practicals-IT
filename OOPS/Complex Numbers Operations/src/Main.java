import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sobj = new Scanner (System.in);
		
		System.out.println("Enter first real part : ");
		int Real1 = sobj.nextInt();
		
		System.out.println("Enter second real part : ");
		int Real2 = sobj.nextInt();
		
		System.out.println("Enter first Imaginary part : ");
		int Imaginary1 = sobj.nextInt();
		
		System.out.println("Enter second imaginary part : ");
		int Imaginary2 = sobj.nextInt();
		
		Complex cobj = new Complex(Real1 , Real2 , Imaginary1 , Imaginary2);
		
		while(true)
		{
			System.out.println("-----------------------------------------");
			System.out.println("1 : Addition");
			System.out.println("2 : Subtraction");
			System.out.println("3 : Multiplication");
			System.out.println("4 : Division");
			System.out.println("5 : Exit");
			System.out.println("-----------------------------------------");
			
			System.out.println("Enter the choice : ");
			int iChoice = sobj.nextInt();
			switch(iChoice)
			{
				case 1:
					cobj.Addition();
					break;
					
				case 2:
					cobj.Subtraction();
					break;
					
				case 3:
					cobj.Multiplication();
					break;
					
				case 4:
					cobj.Division();
					break;
					
				case 5:
					System.out.println("Exiting ....");
					sobj.close();
					return;
					
				default:
					System.out.println("Invalid Choice");
					break;
			}
		}
	}
}
