package com.books.prj.book;

import java.util.Scanner;

import com.books.prj.publication.Publication;

public class Book extends Publication{
	
	Scanner sobj = new Scanner(System.in);
	public String author;
	public int totalbooksell;
	public int totalPrice;
	public int newCopies;
	public int bookSell;
	
	public void getAuthor()
	{
		System.out.println("Enter Author : ");
		author = sobj.nextLine();
	}
	
	public void getBookData()
	{
		getData();
		getAuthor();
	}
	
	public void getTotalCopies()
	{
		System.out.println("Enter new copies : ");
		newCopies = sobj.nextInt();
		this.copies = newCopies + this.copies;
	}
	
	public void totalBooksell()
	{
		System.out.println("Total book sell : " + totalbooksell);
	}
	
	@Override
	public void saleCopy()
	{
		bookSell = this.copies * this.copies;
		totalbooksell = totalbooksell + bookSell;
		totalprice += totalbooksell;
        System.out.print("\n");
        System.out.println("Ordered Book : " + this.title);
        System.out.println("Total Amount : " + bookSell);
        System.out.print("\n");
	}
}
