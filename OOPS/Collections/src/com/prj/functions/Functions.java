package com.prj.functions;

import java.util.ArrayList;
import java.util.Scanner;

public class Functions <T>{
	
	Scanner sobj = new Scanner(System.in);
	ArrayList<T> arr = new ArrayList<T>();
	public int iSize;
	
	public void getData() {
		
		System.out.println("Enter how many elements u want to enter : ");
		iSize = sobj.nextInt();
		
		System.out.println("Enter the elements : ");
		
		for(int i = 0 ; i < iSize ; i++)
		{
			T temp = (T)sobj.next();
			arr.add(temp);
		}
		System.out.println();
	}
	
	public void displayData() {
		
		System.out.println("Array : " + arr);
	}
	
	public void evenNumbers()
	{	
		System.out.println("Even numbers are : ");
		
		for(int i = 0 ; i<iSize ; i++)
		{	
			int num = Integer.parseInt((String) arr.get(i));
			if(num %2 == 0) {
				
				System.out.println(num);
			}
		}
	}
	
	public void oddNumbers()
	{
		System.out.println("Odd numbers are : ");
		
		for(int i = 0 ; i<iSize ; i++)
		{	
			int num = Integer.parseInt((String) arr.get(i));
			if(num %2 != 0) {
				
				System.out.println(num);
			}
		}
	}
	
	
	public void primeNumbers()
	{	
		boolean flag = false;
		
		System.out.println("Prime numbers are : ");
		
		for(int i = 0 ; i<iSize ; i++)
		{	
			flag = false;
			int num = Integer.parseInt((String) arr.get(i));
			
			for(int j = 2 ; j < num ; j++)
			{
				if(num % j == 0) {
					
					flag = true;
					break;
				}	
			}
			if(flag == false)
			{
				System.out.println(arr.get(i));
			}
		}
	}
	
	public void palindrome(String str) {
		String revStr = "";
		
		for(int i = str.length() - 1 ; i >= 0 ; i--) {
			
			revStr = revStr + str.charAt(i);
		}
		
		if(str.equals(revStr))
		{
			System.out.println("It is palindrome");
		}
		else
		{
			System.out.println("It is not palindrome");
		}
	}
	
	
}
