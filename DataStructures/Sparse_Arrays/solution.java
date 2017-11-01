import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
       int n = in.nextInt();
       Map<String, Integer> stringMap = new HashMap<String, Integer>();

       for(int i=0; i<n; ++i) {
           String s = in.next();
           if(stringMap.containsKey(s))
               stringMap.put(s, stringMap.get(s)+1);
           else
               stringMap.put(s, 1);
       }

       int q = in.nextInt();
       for(int i=0; i<q; ++i) {
           String s = in.next();
           if(stringMap.containsKey(s))
                System.out.println(stringMap.get(s));
           else
               System .out.println("0");
       }
    }
}
