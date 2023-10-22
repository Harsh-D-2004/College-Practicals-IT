public class Complex{

	public int Real1;
	public int Real2;
	public int Imaginary1;
	public int Imaginary2;
	
	public Complex()    //Default constructor
	{
		this.Real1 = 0;
		this.Real2 = 0;
		this.Imaginary1 = 0;
		this.Imaginary2 = 0;
	}
	
	public Complex(int Real1 , int Real2 , int Imaginary1 , int Imaginary2)  //Parameterized constructor
	{
		this.Real1 = Real1;
		this.Real2 = Real2;
		this.Imaginary1 = Imaginary1;
		this.Imaginary2 = Imaginary2;
	}
	
	public void Addition()
	{
		int iAns1 = 0;
		iAns1 = Real1 + Real2;
		
		int iAns2 = 0;
		iAns2 = Imaginary1 + Imaginary2;
		
		System.out.println("The addition is : " + (iAns1) + " + " +  (iAns2) + "i");
		System.out.println();
	}
	
	public void Subtraction()
	{
		int iAns1 = 0;
		iAns1 = Real1 - Real2;
		
		int iAns2 = 0;
		iAns2 = Imaginary1 - Imaginary2;
		
		System.out.println("The subtraction is : " + (iAns1) + " + " + (iAns2) + "i");
		System.out.println();
	}
	
	public void Multiplication()
	{
		int iAns1 = 0;
		iAns1 = (Real1 * Real2) - (Imaginary1 * Imaginary2);
		
		int iAns2 = 0;
		iAns2 = (Real1 * Imaginary2) + (Real2 * Imaginary1);
		
		System.out.println("The multiplication is : " + (iAns1) + " + " + (iAns2) + "i");
		System.out.println();
	}
	
	public void Division()
	{
		int Denom = (Real2 * Real2) + (Imaginary2 * Imaginary2);
		
		if(Denom == 0)
		{
			System.out.println("Infinity!");
			return;
		}
		
		int Num1 = (Real1 * Real2) + (Imaginary1 * Imaginary2);
		int Num2 = (Real2 * Imaginary1) - (Real1 * Imaginary2);
		
		int iAns1 = Num1 / Denom;
		int iAns2 = Num2 / Denom;
		
		System.out.println("The division is : " + (iAns1) + " + " + (iAns2) + "i");
		System.out.println();
	}
}