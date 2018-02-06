/**
 * 	Problem : 424-Integer Inquiry.java
 * 	Status  : Accepted
 * 	Date    : 15.09.2015.
 */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		BigInteger number;
		BigInteger sum = BigInteger.ZERO;
		
		while(input.hasNext())
		{
			number = input.nextBigInteger();
			if(number.compareTo(BigInteger.ZERO)== 0)
				break;
			sum = sum.add(number);
		}
		System.out.println(sum);
		
		input.close();
	}
}
