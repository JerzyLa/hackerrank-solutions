import java.io.*;
import java.util.*;

class CountingSort1 {
    int[] solve(int tab[]) {
        int[] result = new int[100];

        for(int i : tab)
            result[i] += 1;

        return result;
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

        CountingSort1 countingSort1 = new CountingSort1();
        for(Integer i : countingSort1.solve(tab))
            System.out.print(i + " ");
    }
}
