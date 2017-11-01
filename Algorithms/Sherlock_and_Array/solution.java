import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static String solve(int[] arr){
        // Complete this function
        int pos = arr.length / 2;
        long left = 0;
        long right = 0;

        for(int i=0; i<pos; ++i)
            left += arr[i];
        for(int i=pos+1; i<arr.length; ++i)
            right += arr[i];

        if( left < right) {
            while(pos < arr.length && left < right) {
                left += arr[pos];
                ++pos;
                right -= arr[pos];
            }
        }
        else  {
            while(pos > 0 && left > right) {
                right += arr[pos];
                --pos;
                left -= arr[pos];
            }
        }

        if(left == right)
            return "YES";
        else
            return "NO";
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for(int a0 = 0; a0 < T; a0++){
            int n = in.nextInt();
            int[] a = new int[n];
            for(int a_i=0; a_i < n; a_i++){
                a[a_i] = in.nextInt();
            }
            String result = solve(a);
            System.out.println(result);
        }
    }
}
