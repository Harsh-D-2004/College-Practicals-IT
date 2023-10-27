package dynamicbinding.prj.rectangle;

import dynamicbinding.prj.shape.Shape;

public class Rectangle extends Shape{

	public Rectangle(double x, double y) {
		super(x, y);
	}

	@Override
	public void getArea() {
		
		double iAns = 0.0;
		iAns = base * height;
		
		System.out.println("The Area is : " + iAns);;
	}

}
