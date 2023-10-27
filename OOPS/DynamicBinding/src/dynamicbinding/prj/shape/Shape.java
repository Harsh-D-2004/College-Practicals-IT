package dynamicbinding.prj.shape;

public abstract class Shape {
	
	public double base;
	public double height;
	
	public abstract void getArea();
	
	public Shape(double x , double y)
	{
		base = x;
		height = y;
	}
}
