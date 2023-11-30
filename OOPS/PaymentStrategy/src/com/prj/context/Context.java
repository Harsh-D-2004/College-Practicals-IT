package com.prj.context;

import com.prj.payment.Payment;

public class Context {
	
	private Payment payment;

	public Context(Payment payment) {
		super();
		this.payment = payment;
	}
	
	public void pay(int amount) {
		payment.pay(amount);
	}

}
