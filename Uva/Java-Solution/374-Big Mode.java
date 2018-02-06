// Accepted .. 
// Date : 31.03.2015 .. 
// Problem : 374-Big Mode ..  

package uvaproblems;

import java.math.BigInteger;
import java.util.Scanner;
 
// this class can't contain public name must be main for submission in uva onlne judge :)
class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args) {
        BigInteger B, P, N;
        while(s.hasNext()) {
            B = s.nextBigInteger();
            P = s.nextBigInteger();
            N = s.nextBigInteger();
             
            String ans = B.modPow(P, N).toString();
            System.out.println(ans);
        }
    }
}
