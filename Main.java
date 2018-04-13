/* 
 * File:   ThePriestMathematician.java
 * Author: YJTHETRUTH
 *
 * Created on February 28, 2018, 11:00 PM
 */
//package thepriestmathematician;
import java.util.Scanner;
import java.math.BigInteger;

/*
 * https://oeis.org/A007664
 * 2^(n-k)-1 moves
 * a(n) = min{2a(k) + 2^(n-k) -1; k<n}
 * a(0) = 0
 *
 * https://codeforces.com/blog/entry/16380
 * Big Integer in C++ requires too much implementation
 * 
 * decided to go with java BigInteger 
 * https://docs.oracle.com/javase/7/docs/api/java/math/BigInteger.html
 *
 *Compiler Error and runtime Error
 *https://discuss.codechef.com/questions/17/error-class-is-public-should-be-declared-in-a-file-named-java-public-class
 */

 class Main {

    /**
     * @param args the command line arguments
     */
    static final int max = 10005;
    static int N = 0;
    static BigInteger[] a = new BigInteger[max];  
    
    public static void TowerofHanoi (){
        
        a[0] = BigInteger.ZERO;        
        BigInteger k = BigInteger.ONE;       

        int counter = 1;
             
        for(int i = 1; i < max;)
        {
            for ( int j = 0; j < counter && i < max; ++j)
            {
                a[i] = a[i-1].add(k);
                ++i;
            }
            k = k.add(k);
            ++counter;
        }
        
    }
    public static void main (String[] args) 
    {
       Scanner sc = new Scanner(System.in);
       
       Main.TowerofHanoi();
       
        while(sc.hasNext())
        {            
            N = sc.nextInt();           
           System.out.println(a[N]);
        }
    }
}
