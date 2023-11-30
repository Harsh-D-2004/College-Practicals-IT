package com.prj.paymentmethods;

import com.prj.payment.Payment;

public class CreditCard implements Payment{

	@Override
	public void pay(int amount) {
		
		if(amount > 100000) {
			System.out.println("Amount more than 100000");
			return;
		}
		else
		{	
			System.out.println("Using Credit Card.......");
			System.out.println("Payment Successfull...........");
			System.out.println("Amount : " + amount + " debited from account");
			System.out.println("Generating Slip..........");
			System.out.println("Thankyou........");
		}
		
	}

}
