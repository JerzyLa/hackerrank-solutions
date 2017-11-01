import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static void AbsolutePermutation(int n, int diff) {
      if(diff==0 || ((n%diff)==0 && (n/diff)%2==0)) {
         int mul =1;
         for(int i=1; i<=n; ++i) {
            if(i>(mul+1)*diff)
               mul+=2;

            if(i<=mul*diff)
               System.out.print((i+diff) + " ");
            else
               System.out.print((i-diff) + " ");
         }
      }
      else {
         System.out.print("-1");
      }
   }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int k = in.nextInt();
            AbsolutePermutation(n,k);
            System.out.println();
        }
    }
}
