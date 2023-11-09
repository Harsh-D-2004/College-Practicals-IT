package com.prj.main;

import java.util.Scanner;

import com.prj.service.FileHandling;

public class Main {
	public static void main(String args[]) {
		
		Scanner sobj = new Scanner(System.in);
		
		FileHandling fobj = new FileHandling();
		
		while(true) {
			
			System.out.println("--------------------------------");
			System.out.println("1 : Create Database");
			System.out.println("2 : Write to Database");
			System.out.println("3 : Update Database");
			System.out.println("4 : Delete Database");
			System.out.println("5 : Exit");
			System.out.println("--------------------------------");
			
			System.out.println("Enter the Choice : ");
			int iChoice = sobj.nextInt();
			
			switch(iChoice) {
				
				case 1:
					fobj.createDatabase();
					break;
					
				case 2:
					fobj.writeToDatabase();
					break;
					
				case 3:
					fobj.writeToDatabase();
					break;
					
				case 4:
					fobj.deleteDatabase();
					break;
					
				case 5:
					return;
					
				default:
					System.out.println("Error");
					break;
			}
		}
	}
}
