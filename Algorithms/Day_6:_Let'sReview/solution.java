import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        Vector<String> testCases=new Vector<String>();

        int T = in.nextInt();
        for(int i=0; i<T; ++i) {
            testCases.add(in.next());
        }

        for(int i=0; i<testCases.size(); ++i) {
            String evenChars = new String();
            String oddChars = new String();

            for(int j=0; j<testCases.get(i).length(); ++j)
                if(j%2 == 0)
                    evenChars += testCases.get(i).charAt(j);
                else
                    oddChars += testCases.get(i).charAt(j);

            System.out.println(evenChars + " " + oddChars);
        }
    }
}
