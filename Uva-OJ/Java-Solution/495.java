import java.math.BigInteger;
import java.util.Scanner;

public class FibonacciFrozen {
	public static String[] fibNumbe = new String[5001];
	
	public static void main(String[] args) {
		generateFibNumber();
		
		Scanner input = new Scanner(System.in);
		
		int n;
		while(input.hasNext()) 
		{
      	n = input.nextInt();
      	System.out.println("The Fibonacci number for " + n + " is " +fibNumbe[n]);
		}
		
		input.close();
	}
	
	public static void generateFibNumber() 
	{
		BigInteger fib1 = BigInteger.ZERO;
		BigInteger fib2 = BigInteger.ONE;
		BigInteger fibn;
		
		fibNumbe[0] = "0";
		fibNumbe[1] = "1";
		
		for(int i = 2; i < 5001; i++)
		{
			fibn = fib1.add(fib2);
			
			fibNumbe[i] = fibn.toString();
			
			fib1 = fib2;
			fib2 = fibn;
		}
	}

}
