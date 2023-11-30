package com.prj.paymentmethods;

import com.prj.payment.Payment;

public class PayPal implements Payment{
	
	@Override
	public void pay(int amount) {
		
		if(amount > 50000) {
			System.out.println("Amount more than 50000");
			return;
		}
		else
		{
			System.out.println("Using PayPal.......");
			System.out.println("Payment Successfull...........");
			System.out.println("Amount : " + amount + " debited from account");
			System.out.println("Generating Slip..........");
			System.out.println("Thankyou........");
		}
		
	}

}
