import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        String hackerrank = "hackerrank";
        for(int a0 = 0; a0 < q; a0++){
            String s = in.next();
            int j=0;
            // your code goes here
            for(int i=0; i<s.length() && j<hackerrank.length(); ++i) {
                if(s.charAt(i) == hackerrank.charAt(j))
                    ++j;
            }

            if(j == hackerrank.length()) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}
