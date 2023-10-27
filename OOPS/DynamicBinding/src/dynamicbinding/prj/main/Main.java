package dynamicbinding.prj.main;

import java.util.Scanner;

import dynamicbinding.prj.rectangle.Rectangle;
import dynamicbinding.prj.triangle.Triangle;

public class Main {
	public static void main(String Args[])
	{	
		int iChoice = 0;
		int iBase = 0;
		int iHeight = 0;
		
		Scanner sobj = new Scanner(System.in);
		
		while(true)
		{
			System.out.println("1 : Area of Rectangle");
			System.out.println("2 : Area of Triangle");
			System.out.println("3 : Exit");
			
			System.out.println("Enter Choice : ");
			iChoice = sobj.nextInt();
			
			switch(iChoice)
			{
				case 1:
					System.out.println("Enter Base : ");
					iBase = sobj.nextInt();
					System.out.println("Enter Height : ");
					iHeight = sobj.nextInt();
					
					Rectangle robj = new Rectangle(iBase , iHeight);
					robj.getArea();
					break;
					
				case 2:
					System.out.println("Enter Base : ");
					iBase = sobj.nextInt();
					System.out.println("Enter Height : ");
					iHeight = sobj.nextInt();
					
					Triangle tobj = new Triangle(iBase , iHeight);
					tobj.getArea();
					break;
					
				case 3:
					return;
					
				default:
					System.out.println("Invalid choice");
					break;
			}
		}
	}
}
