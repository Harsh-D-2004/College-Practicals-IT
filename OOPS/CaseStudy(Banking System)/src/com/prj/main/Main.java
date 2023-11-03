package com.prj.main;

import java.util.Scanner;

import com.prj.sbi.StateBankOfIndia;

public class Main {
	public static void main(String Args[])
	{	
		Scanner sobj = new Scanner(System.in);
		
		System.out.println("-------------------------------------------------------");
		System.out.println("Choose bank : ");
		System.out.println("1 : State Bank Of India");
		System.out.println("2 : Bank of Baroda");
		System.out.println("3 : ICICI Bank");
		System.out.println("-------------------------------------------------------");
		
		int iChoice1 = 0;
		
		System.out.println("Enter Choice : ");
		iChoice1 = sobj.nextInt();
		
		System.out.println("-------------------------------------------------------");
		
		switch(iChoice1)
		{
			case 1:
				System.out.println("Welcome to State Bank of India");
				break;
				
			case 2:
				System.out.println("Welcome to Bank of Baroda");
				break;
				
			case 3:
				System.out.println("Welcome to ICICI Bank");
				break;
			
			default:
				System.out.println("Error");
				break;
		}
		
		StateBankOfIndia obj = new StateBankOfIndia();
		
		while(true)
		{
			System.out.println("-------------------------------------------------------");
			System.out.println("1 : Create Account");
			System.out.println("2 : Deposit");
			System.out.println("3 : Withraw");
			System.out.println("4 : Receipt");
			System.out.println("5 : Exit");
			System.out.println("-------------------------------------------------------");
			
			System.out.println("Choose : ");
			int iChoice2 = sobj.nextInt();
			
			System.out.println("-------------------------------------------------------");
			
			switch(iChoice2)
			{
				case 1:
					obj.getAccDetails();
					System.out.println("Account has been created successfully.........");
					break;
				
				case 2:
					obj.deposit();
					System.out.println("Money deposited successfully............");
					break;
					
				case 3:
					obj.withraw();
					System.out.println("Money withrawed successfully ...........");
					break;
					
				case 4:
					obj.displayAccDetails();
					System.out.println("Thank you............");
					break;
					
				case 5:
					System.out.println("Thankyou for giving a chance to serve you.........");
					return;
					
				default:
					System.out.println("Error");
					break;
			}
			
		}
		
		
	}
}
