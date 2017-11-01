import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static long maximumSum(long[] a, long m) {
        // Complete this function
        // 1. Create prefix table: prefix[i] = (a[0] + .. + a[i]) % M
        long[] prefix = new long[a.length];
        long curr = 0;
        for(int i=0; i<a.length; ++i) {
            curr = (curr+a[i])%m;
            prefix[i] = curr;
        }

        // Every subarry sum could be constructed as difference of two prefix tables.
        // 2. sumSubarray(i,j) = (prefix[j] - prefix[i] + M)%M. So solution is to find maximum. BF solution.
        long result = 0;
        for(int i=0; i<prefix.length-1; ++i) {
            for(int j=i+1; j<prefix.length; ++j)
                result = Math.max((prefix[j] - prefix[i] + m)%m, result);
        }
        for(int j=0; j<prefix.length; ++j)
            result = Math.max((prefix[j] + m)%m, result);

        return result;
    }

    static long fasterMaximumSum(long[] a, long m) {
        // 1. Create prefix table: prefix[i] = (a[0] + .. + a[i]) % M
        long[] prefix = new long[a.length];
        long curr = 0;
        for(int i=0; i<a.length; ++i) {
            curr = (curr+a[i])%m;
            prefix[i] = curr;
        }

        long result = 0;
        TreeSet<Long> sorted = new TreeSet<Long>();
        sorted.add(prefix[0]);
        for(int i=1; i<prefix.length; ++i) {
            /// find upper_bound
            Long upper_bound = sorted.ceiling(prefix[i]);
            if(upper_bound != null)
                result = Math.max((prefix[i] - upper_bound + m)%m, result);
            sorted.add(prefix[i]);
        }
        for(int j=0; j<prefix.length; ++j)
            result = Math.max((prefix[j] + m)%m, result);

        return result;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for(int a0 = 0; a0 < q; a0++){
            int n = in.nextInt();
            long m = in.nextLong();
            long[] a = new long[n];
            for(int a_i = 0; a_i < n; a_i++){
                a[a_i] = in.nextLong();
            }
            long result = fasterMaximumSum(a, m);
            System.out.println(result);
        }
        in.close();
    }
}
