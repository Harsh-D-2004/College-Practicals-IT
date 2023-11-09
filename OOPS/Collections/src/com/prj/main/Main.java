package com.prj.main;

import java.util.Scanner;

import com.prj.functions.Functions;

public class Main {
	public static void main(String args[])
	{	
		Scanner sobj = new Scanner(System.in);
		Functions<Object> fobj = new Functions<Object>();
		
		while(true)
		{	
			System.out.println("---------------------------------------");
			System.out.println("1 : Enter Integers");
			System.out.println("2 : Enter String");
			System.out.println("3 : Exit");
			System.out.println("---------------------------------------");
			
			System.out.println("Enter Choice : ");
			int iChoice = sobj.nextInt();
			
			switch(iChoice) {
			
				case 1:
					fobj.getData();
					fobj.displayData();
					fobj.evenNumbers();
					fobj.oddNumbers();
					fobj.primeNumbers();
					break;
					
				case 2:
					System.out.println("Enter the String : ");
					String str = sobj.next();
					fobj.palindrome(str);
					break;
					
				case 3:
					System.out.println("exiting...............");
					return;
					
				case 4:
					System.out.println("error");
					break;
			}
		}
	}
}
