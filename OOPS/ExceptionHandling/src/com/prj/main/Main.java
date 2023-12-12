package com.prj.main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sobj = new Scanner(System.in);
		
		try {
			String num1;
			String num2;
			float iAns = 0.0f;

			System.out.println("Enter Number 1 : ");
			num1 = sobj.nextLine();

			System.out.println("Enter Number 2 : ");
			num2 = sobj.nextLine();

			int connum1 = Integer.parseInt(num1);
			int connum2 = Integer.parseInt(num2);

			iAns = connum1 / connum2;

			System.out.println("The division is : " + iAns);
			
			int Arr[] = new int[4];
			
			System.out.println("Enter the elements : ");
			
			for(int i = 0 ; i < 6 ; i++) {
				Arr[i] = sobj.nextInt();
			}

			}catch (ArithmeticException aobj) {

				System.out.println("Arithmetic Exception occured ");

			}
			catch(NumberFormatException nobj)
			{
				System.out.println("Number format exception occured ");

			}
			catch(ArrayIndexOutOfBoundsException nobj)
			{
				System.out.println("ArrayIndexOutOfBoundsException occured  ");

			}
			catch(Exception eobj)
			{
				eobj.printStackTrace();
			}
	}

}
