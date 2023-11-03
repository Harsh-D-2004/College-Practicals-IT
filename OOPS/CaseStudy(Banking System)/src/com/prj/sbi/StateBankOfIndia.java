package com.prj.sbi;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

import com.prj.bank.Bank;

public class StateBankOfIndia implements Bank{
	
	public long accId;
	public String accHolderName;
	public String accName;
	public long ifsc;
	public long contactNo;
	public int age;
	
	public int deposit;
	public int withraw;
	public static int balance;
	
	
	@Override
	public void getAccDetails() {
		
		Scanner sobj = new Scanner(System.in);
		
		System.out.println("Enter Account ID : ");
		accId = sobj.nextLong();
		
		System.out.println("Enter Account Holder name : ");
		accHolderName = sobj.next();
		
		System.out.println("Enter Account Name : ");
		accName = sobj.next();
		
		System.out.println("Enter IFSC code : ");
		ifsc = sobj.nextLong();
		
		System.out.println("Enter Account Holder Contact No : ");
		contactNo = sobj.nextLong();
		
		System.out.println("Enter AccountHolder Age : ");
		age = sobj.nextInt();
		
	}
	
	@Override
	public int deposit() {
		
		Scanner sobj = new Scanner(System.in);
		
		System.out.println("Enter the money you want to deposit : ");
		deposit = sobj.nextInt();
		
		balance = balance + deposit;
		
		return balance;
	}
	
	@Override
	public int withraw() {
		
		Scanner sobj = new Scanner(System.in);
		
		System.out.println("Enter the money you want to withraw : ");
		withraw = sobj.nextInt();
		
		balance = balance - withraw;
		
		return balance;
	}
	
	@Override
	public void displayAccDetails() {
		
		System.out.println("The Account id is : " + accId);
		
		DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");  
		LocalDateTime now = LocalDateTime.now();  
		System.out.println("Login time : " + dtf.format(now));  
		
		System.out.println("The amount withrawn : " + withraw);
		System.out.println("The amount deposited : " + deposit);
		System.out.println("The balance : " + balance);
		
	}
	
}
