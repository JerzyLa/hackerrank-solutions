import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String S = in.next();
        int result = 0;
        for(int i=0; i<S.length(); ++i) {
         if((i-1)%3 == 0) {
            if(S.charAt(i) != 'O')
               ++result;
         }
         else if(S.charAt(i) != 'S') {
            ++result;
         }
      }

        System.out.println(result);
    }
}
