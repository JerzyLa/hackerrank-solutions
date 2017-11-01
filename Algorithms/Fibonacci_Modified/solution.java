import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static void main(String args[] ) throws Exception {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        Scanner in = new Scanner(System.in);
        BigInteger t1 = BigInteger.valueOf(in.nextInt());
        BigInteger t2 = BigInteger.valueOf(in.nextInt());
        int n = in.nextInt();

        BigInteger result = new BigInteger("0");
        for(int i=2; i<n; ++i) {
            result = t1.add( t2.multiply(t2) );
            t1 = t2;
            t2 = result;
        }

        System.out.println(result);
    }
}
