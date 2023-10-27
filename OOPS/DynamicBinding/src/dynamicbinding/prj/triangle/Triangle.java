package dynamicbinding.prj.triangle;

import dynamicbinding.prj.shape.Shape;

public class Triangle extends Shape{

	public Triangle(double x, double y) {
		super(x, y);
	}

	@Override
	public void getArea() {
		
		double iAns = 0.0;
		iAns = 0.5 * base * height;
		
		System.out.println("The Area is : " + iAns);;
		
	}
	
}
