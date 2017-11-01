import java.io.*;
import java.util.*;

 class RunningTimeOfAlgorithms {

    int solve(int[] tab) {
        int result = 0;

        for(int i=1; i<tab.length; ++i) {
            int j = i-1;
            while(j>=0 && tab[j+1] < tab[j]) {
                int tmp = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = tmp;
                --j;
                ++result;
            }
        }

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

        RunningTimeOfAlgorithms runningTimeOfAlgorithms = new RunningTimeOfAlgorithms();
        System.out.println(runningTimeOfAlgorithms.solve(tab));
    }
}
