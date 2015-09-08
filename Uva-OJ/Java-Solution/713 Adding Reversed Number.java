/**
  * Status :  Accepted .. 
  * Date : 01. 04. 2015.. 
  * Problem: 713 - Adding Reversed Numbers.. 
  **/ 
package uvaproblems;

import java.math.BigInteger;
import java.util.Scanner;
 
class Main2 {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        BigInteger a, b;
        int tCase;
        tCase = sc.nextInt();
        for(int i = 0; i < tCase; i++) {
            a = sc.nextBigInteger();
            b = sc.nextBigInteger();
            // reverse a string a and assign it to a;
            String num1 = a.toString();
            String rev1 = new StringBuffer(num1).reverse().toString();
             
             
            // reverse a string b and assign it to b;
            String num2 = b.toString();
            String rev2 = new StringBuffer(num2).reverse().toString();
             
            // put the value of rev1 & rev2 into BigInteger;
            BigInteger aBig = new BigInteger(rev1);
            BigInteger bBig = new BigInteger(rev2);
             
            // add our two big number;
            BigInteger ans = aBig.add(bBig);
             
            // convert big integer to string and assign it to temp;
            //String temp = ans.toString();
             
             
            // reverse temp;
            //String rev3 = new StringBuffer(temp).reverse().toString();
            //char[] FinalAns = rev3.toCharArray();
             
            ///for(int j = 0; j < FinalAns.length; j++) {
                //if(FinalAns[j] != '0') {
                    //System.out.print(FinalAns[j]);
                //}
            //}
            //System.out.println();
             
            StringBuilder sBuilder = new StringBuilder(ans.toString()).reverse();
            ans = new BigInteger(sBuilder.toString());
             
            System.out.println(ans);
             
        }
 
    }
 
}
