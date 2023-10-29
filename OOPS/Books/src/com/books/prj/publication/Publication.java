package com.books.prj.publication;

import java.util.Scanner;

public class Publication {
	
	public String title;
	public int copies;
	public double price;
	public static double totalprice;
	
	Scanner sobj = new Scanner(System.in);
	
	public void getData()
	{
		System.out.println("Enter title : ");
		title = sobj.nextLine();
		
		System.out.println("Enter copies : ");
		copies = sobj.nextInt();
		
		System.out.println("Enter price : ");
		price = sobj.nextDouble();
	}
	
	public void saleCopy()
	{
		System.out.println("Total sale : " + totalprice);
	}
	
	public void totalPublicationSell()
	{
		System.out.println("Total publication sale : " + totalprice);
	}
	
}
