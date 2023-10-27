package inter.prj.main;

import java.util.Scanner;

import inter.prj.bicycle.Bicycle;
import inter.prj.bike.Bike;
import inter.prj.car.Car;

public class Main {
	
	public static void main(String Args[])
	{	
		Scanner sobj = new Scanner(System.in);
		
		Bicycle bobj = new Bicycle();
		Bike bbobj = new Bike();
		Car cobj = new Car();
		
		int iChoice = 0;
		
		System.out.println("Bike : ");
		
		while(true)
		{	
			System.out.println("1 : Speed Change");
			System.out.println("2 : Apply Brakes");
			System.out.println("3 : Gear Change");
			System.out.println("4 : Display");
			
			System.out.println("Enter Choice : ");
			iChoice = sobj.nextInt();
			
			switch(iChoice)
			{
				case 1:
					System.out.println("Enter how much to change speed : ");
					int speed = sobj.nextInt();
					bbobj.speedChange(speed);
					bbobj.display();
					break;
						
				case 2:
					System.out.println("Enter how much to apply breaks : ");
					int breaks = sobj.nextInt();
					bbobj.applyBreaks(breaks);
					bbobj.display();
					break;
					
				case 3:
					System.out.println("Enter which gear to change : ");
					int gear = sobj.nextInt();
					bbobj.gearChange(gear);
					bbobj.display();
					break;
				
				case 4:
					bbobj.display();
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
