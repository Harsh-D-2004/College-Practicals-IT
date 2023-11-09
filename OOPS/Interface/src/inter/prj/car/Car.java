package inter.prj.car;

import inter.prj.vehicle.Vehicle;

public class Car implements Vehicle{
	
	private int gear;
	private int speed;
	final int maxspeed = 200;
	
	@Override
	public void gearChange(int a) {
		
		if(a > 0 && a < maxspeed)
		{
			gear = a;
			System.out.println("Gear : " + gear);
		}
		else
		{
			System.out.println("Gear cannot be negative");
		}
		
	}

	@Override
	public void speedChange(int a) {
		
		if(a < maxspeed)
		{
			speed = speed + a;
			if(gear == 1 && speed <= 25)
			{
				System.out.println("Speed Changed : " + a);
			}
			else if(gear == 2 && speed > 25 && speed <= 50)
			{
				System.out.println("Speed Changed : " + a);
			}
			else if(gear == 3 && speed > 50 && speed <= 80)
			{
				System.out.println("Speed Changed : " + a);
			}
			else if(gear == 4 && speed > 80)
			{
				System.out.println("Speed Changed : " + a);
			}
			else
			{
				System.out.println("Error");
				speed = speed - a;
			}
		}
		else
		{
			System.out.println("Speed cannot be changed");
			speed = speed - a;
		}
		
	}

	@Override
	public void applyBreaks(int a) {
		
		speed = speed - a;
		System.out.println("Reduced speed : " + speed);
		
	}
	
	public void display()
	{
		System.out.println("Speed : " + speed);
		System.out.println("Gear : " + gear);
	}
	
}
