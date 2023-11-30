package com.prj.paymentmethods;

import com.prj.payment.Payment;

public class BitCoin implements Payment{
	
	@Override
	public void pay(int amount) {
		
		if(amount > 10) {
			System.out.println("Amount more than 10BitCoins");
			return;
		}
		else
		{
			System.out.println("Using BitCoin.......");
			System.out.println("Payment Successfull...........");
			System.out.println("Amount : " + amount + " debited from account");
			System.out.println("Generating Slip..........");
			System.out.println("Thankyou........");
		}
		
	}

}
