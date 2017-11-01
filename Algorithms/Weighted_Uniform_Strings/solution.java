import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void solve(Map<Character, Integer> m, int x) {
        for(Map.Entry<Character, Integer> e : m.entrySet()) {
            int c = e.getKey()-'a'+1;
            if(x%c==0 && x/c <= e.getValue()) {
                System.out.println("Yes");
                return;
            }
        }

        System.out.println("No");
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        int n = in.nextInt();

        Map<Character, Integer> m = new HashMap<Character, Integer>();
        Character prev = s.charAt(0);
        int sum = 1;
        for(int i=1; i<s.length(); ++i) {
            if(s.charAt(i) == prev) {
                ++sum;
            }
            else {
                if(m.containsKey(prev) && sum < m.get(prev))
                    ;
                else
                    m.put(prev, sum);
                sum = 1;
            }
            prev = s.charAt(i);
        }
        if(m.containsKey(prev) && sum < m.get(prev))
            ;
        else
            m.put(prev, sum);

        for(int a0 = 0; a0 < n; a0++){
            int x = in.nextInt();
            // your code goes here
            solve(m, x);
        }
    }
}
