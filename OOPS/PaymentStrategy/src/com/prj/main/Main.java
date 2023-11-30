package com.prj.main;

import java.util.Scanner;

import com.prj.context.Context;
import com.prj.paymentmethods.BitCoin;
import com.prj.paymentmethods.CreditCard;
import com.prj.paymentmethods.PayPal;

public class Main {

	public static void main(String[] args) {
		
		Scanner sobj = new Scanner(System.in);
		
		int amount = 0;
		
		while(true) {
			
			System.out.println("-----------------------------");
			System.out.println("1 : Credit Card");
			System.out.println("2 : PayPal");
			System.out.println("3 : BitCoin");
			System.out.println("4 : Exit");
			System.out.println("-----------------------------");
			
			int iChoice = 0;
			
			System.out.println("Enter the Choice : ");
			iChoice = sobj.nextInt();
			
			switch(iChoice) {
				
				case 1:
					Context context = new Context(new CreditCard());
					
					System.out.println("Enter the amount : ");
					amount = sobj.nextInt();
					context.pay(amount);
					break;
					
				case 2:
					Context context2 = new Context(new PayPal());
					
					System.out.println("Enter the amount : ");
					amount = sobj.nextInt();
					context2.pay(amount);
					break;
					
				case 3:
					Context context3 = new Context(new BitCoin());
					
					System.out.println("Enter the amount : ");
					amount = sobj.nextInt();
					context3.pay(amount);
					break;
					
				case 4:
					System.out.println("Exiting............");
					return;
					
				default:
					System.out.println("Enter proper Choice");
			}
		}

	}

}
