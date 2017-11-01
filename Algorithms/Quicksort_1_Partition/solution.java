import java.io.*;
import java.util.*;

class QuickSort1 {
    List<Integer> solve(int[] tab) {
        int p = tab[0];
        List<Integer> left = new ArrayList<Integer>();
        List<Integer> right = new ArrayList<Integer>();

        for(int i=0; i<tab.length; ++i) {
            if(tab[i] < p)
                left.add(tab[i]);
            else if(tab[i] > p)
                right.add(tab[i]);
        }

        left.add(p);
        left.addAll(right);

        return left;
    }

}

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int tab[] = new int[n];
        for(int i=0; i<n; ++i)
            tab[i] = in.nextInt();

        QuickSort1 quickSort1 = new QuickSort1();
        for(Integer i : quickSort1.solve(tab))
            System.out.print(i + " ");
    }
}
