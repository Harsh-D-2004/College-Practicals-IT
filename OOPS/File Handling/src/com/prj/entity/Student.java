package com.prj.entity;

import java.util.Scanner;

public class Student {
	
	private String id;
	private String name;
	private String domain;
	private String year;
	
	public void getData() {
		
		Scanner sobj = new Scanner(System.in);
		
		System.out.println("Enter id : ");
		id = sobj.next();
		
		System.out.println("Enter name : ");
		name = sobj.next();
		
		System.out.println("Enter domain : ");
		domain = sobj.next();
		
		System.out.println("Enter year : ");
		year = sobj.next();
	}
	
	public String displayData() {
		return "id : " + id + "	name : " + name + "	domain : " + domain + "	year : " + year;
	}
	
}
