import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

   public static int solve(List<Integer> h, int k) {
      Collections.sort(h);

      int i=0;
      int result = 0;
      while(i < h.size())
      {
         ++result;
         int pos = h.get(i) + k;
         while(i<h.size() && h.get(i) <= pos) {
            ++i;
         }
         pos = h.get(--i) + k;
         while(i < h.size() && h.get(i) <= pos) {
            ++i;
         }
      }

      return result;
   }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        Integer[] x = new Integer[n];
        for(int x_i=0; x_i < n; x_i++){
            x[x_i] = in.nextInt();
        }

        System.out.println(solve(Arrays.asList(x), k));
    }
}
