package com.prj.main;

import java.util.Scanner;

import com.prj.service.FileHandling;

public class Main {
	public static void main(String args[]) {
		
		Scanner sobj = new Scanner(System.in);
		
		FileHandling fobj = new FileHandling();
		String id = "";
		
		while(true) {
			
			System.out.println("--------------------------------");
			System.out.println("1 : Create Database");
			System.out.println("2 : Write to Database");
			System.out.println("3 : Update Database");
			System.out.println("4 : Delete Database");
			System.out.println("5 : Read Database");
			System.out.println("6 : Search Database");
			System.out.println("7 : Delete Record");
			System.out.println("8 : Exit");
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
					fobj.updateDatabase();
					break;
					
				case 4:
					fobj.deleteDatabase();
					break;

				case 5:
					fobj.readDatabase();
					break;
					
				case 6:
					System.out.println("Enter the id to search : ");
					id = sobj.next();

					fobj.searchDatabase("id : " + id);
					break;

				case 7:
					System.out.println("Enter the id to search : ");
					id = sobj.next();

					fobj.deleteRecord("id : " + id);
					break;

				case 8:
					System.out.println("Exiting.............");
					return;
					
				default:
					System.out.println("Error");
					break;
			}
		}
	}
}
