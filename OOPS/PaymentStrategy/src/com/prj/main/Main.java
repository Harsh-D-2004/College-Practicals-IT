package com.prj.main;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

interface Payment{ //INTERFACE
public void pay(int amount);
}

class DebitCard implements Payment{ //DEBITCARD

Scanner sobj = new Scanner(System.in);

@Override
public void pay(int amount) {

System.out.println("Paying Through DebitCard....");

if(amount > 100000) //VALIDATION
{
System.out.println("Amount is too large");
return;
}

System.out.println("Payment successfull through DebitCard");
System.out.println("Amount : " + amount + " successfully debited");
System.out.println("Generating payslip.........");
System.out.println("Thankyou.......");
}

}

class PayPal implements Payment{ //PAYPAL

Scanner sobj = new Scanner(System.in);

@Override
public void pay(int amount) {

System.out.println("Paying Through PayPal....");

if(amount > 10000) //VALIDATION
{
System.out.println("Amount is too large");
return;
}

System.out.println("Payment successfull through PayPal");
System.out.println("Amount : " + amount + " successfully debited");
System.out.println("Generating payslip.........");
System.out.println("Thankyou.......");
}

}

class BitCoin implements Payment{ //BITCOIN

Scanner sobj = new Scanner(System.in);

@Override
public void pay(int amount) {

System.out.println("Paying Through BitCoin....");

if(amount > 10) //VALIDATION
{
System.out.println("Amount is too large");
return;
}

System.out.println("Payment successfull through BitCoin");
System.out.println("Amount : " + amount + " successfully debited");
System.out.println("Generating payslip.........");
System.out.println("Thankyou.......");
}

}

class Context{ //CONTEXT

private Payment payment;

public Context(Payment payment) {
super();
this.payment = payment;
}

public void pay(int amount) {
payment.pay(amount);
}
}

class ShoppingCart{ //SHOPPINGCART

private List<String> list=new ArrayList<String>();     //DECLARING LIST



private List<String> cart=new ArrayList<String>(); //DECLARING LIST

private static int sum;

public ShoppingCart() { //DEFAULTCONTRUCTOR
addItemsinList();
sum = 0;
}

public void addItemsinList() {
list.add("tomato");
list.add("potato");
list.add("juice");
list.add("apple");
list.add("chikoo");
list.add("watermelon");
list.add("bottle");
}

public void showItems() {

System.out.println("Items : " + list);
}

public void showItemsfromCart() {

System.out.println("Cart : " + cart);
}

public void addItem(String item) {

for(String i : list) { //VALIDATION

if(item.equals(i)) {
cart.add(item);
sum = sum + 200;
System.out.println("Item added successfully");
break;
}
else
{
cart.add(item);
sum = sum + 200;
System.out.println("Item added successfully");
break;
}
}

}

public void removeItem(String item) {

for(String i : cart) {

if(item.equals(i)) { //VALIDATION
cart.remove(item);
sum = sum - 200;
System.out.println("Item removed successfully");
break;
}
else
{
System.out.println("Item not in your cart");
break;
}
}

}

public void totalAmount() {

System.out.println("Total Amount : " + sum);

}

}



public class Main { //MAIN CLASS

public static void main(String[] args) {

Scanner sobj = new Scanner(System.in);

Context context;
int iValue = 0;
int iChoice = 0;
String item;
boolean bRet = false;

ShoppingCart sc = new ShoppingCart();

while(true) { //SHOPPING CART LOOP

System.out.println("---------------------------------------------");
System.out.println("1 : Display Items from shop");
System.out.println("2 : Add Item in Cart");
System.out.println("3 : Remove Item from cart");
System.out.println("4 : Display Cost");
System.out.println("6 : Display items from cart");
System.out.println("5 : Exit");
System.out.println("---------------------------------------------");

System.out.println("Enter the choice : ");
iChoice = sobj.nextInt();

switch(iChoice) {

case 1:
sc.showItems();
break;

case 3:
System.out.println("Enter item : ");
item = sobj.next();
sc.removeItem(item);
break;

case 2:
System.out.println("Enter item : ");
item = sobj.next();
sc.addItem(item);
break;

case 4:
sc.totalAmount();
break;

case 5:
bRet = true;
break;

case 6:
sc.showItemsfromCart();
break;
}
if(bRet == true) {
break;
}
}

System.out.println("Redirecting to payment methods..........");

while(true) { //PAYMENT MENTHODS LOOP
System.out.println("---------------------------------------------");
System.out.println("1 : DebitCard");
System.out.println("2 : PayPal");
System.out.println("3 : BitCoin");
System.out.println("4 : Exit");
System.out.println("---------------------------------------------");

System.out.println("Enter the choice : ");
iChoice = sobj.nextInt();

switch(iChoice) {

case 1:
context = new Context(new DebitCard());

System.out.println("Enter the amount u want to pay : ");
iValue = sobj.nextInt();

context.pay(iValue);

break;

case 2:
context = new Context(new PayPal());

System.out.println("Enter the amount u want to pay : ");
iValue = sobj.nextInt();

context.pay(iValue);

break;

case 3:
context = new Context(new BitCoin());

System.out.println("Enter the amount u want to pay : ");
iValue = sobj.nextInt();

context.pay(iValue);

break;

case 4:
System.out.println("Exiting........");
return;

default:
System.out.println("Enter proper choice");
break;

}
}


}

}
