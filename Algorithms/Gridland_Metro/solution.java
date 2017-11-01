import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
   static int merge(List<Integer> l) {
      int result = 0;
      Map<Integer, Integer> map = new TreeMap<Integer, Integer>();
      for(int i=0; i<l.size(); i+=2) {
         if(map.containsKey(l.get(i))) {
           if(l.get(i+1) > map.get(l.get(i)))
              map.put(l.get(i), l.get(i+1));
         }
         else  {
            map.put(l.get(i), l.get(i+1));
         }
      }

      Integer a = 0;
      Integer b = 0;
      for(Map.Entry<Integer, Integer> entry : map.entrySet()) {
         if(a==0 || b==0) {
            a = entry.getKey();
            b = entry.getValue();
         }
         else if(entry.getKey() <= b && b < entry.getValue()) {
            b = entry.getValue();
         }
         else if(entry.getKey() > b) {
            result += b-a+1;
            a = entry.getKey();
            b = entry.getValue();
         }
      }

      result += b-a+1;
      return result;
   }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner reader = new Scanner(System.in);
        long n = reader.nextInt();
        long m = reader.nextInt();
        int k = reader.nextInt();
        int r,c1,c2;
        Map<Integer, List<Integer>> reils = new HashMap<Integer, List<Integer>>();

        for(int i=0; i<k; ++i) {
           r = reader.nextInt();
           c1 = reader.nextInt();
           c2 = reader.nextInt();
           if(reils.containsKey(r)) {
               reils.get(r).add(c1);
               reils.get(r).add(c2);
           }
           else {
               reils.put(r, new ArrayList<Integer>(Arrays.asList(c1, c2)));
           }
        }

        long free = n*m;
        for(Map.Entry<Integer, List<Integer>> entry : reils.entrySet()) {
           free -= merge(entry.getValue());
        }

        System.out.println(free);
    }
}
