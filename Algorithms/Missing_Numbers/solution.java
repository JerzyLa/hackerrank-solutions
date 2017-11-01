import java.io.*;
import java.util.*;

public class Solution {

    public static void sortedInsertion(int first, int last, List<Integer> arr, Integer el) {
        if(first==last) {
            arr.add(first, el);
            return;
        }

        if(last-first == 1) {
            if(el < arr.get(first))
                arr.add(first, el);
            else
                arr.add(last, el);
            return;
        }

        int pos = (last+first) / 2;
        if(arr.get(pos) == el) {
            arr.add(pos, el);
            return;
        }
        else if(arr.get(pos) < el)
            sortedInsertion(pos+1, last, arr, el);
        else
            sortedInsertion(first, pos, arr, el);
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */

        Scanner in = new Scanner(System.in);
        List<Integer> aArr = new ArrayList<Integer>();
        List<Integer> bArr = new ArrayList<Integer>();

        int n = in.nextInt();
        for(int i=0; i<n; ++i)
            sortedInsertion(0, aArr.size(), aArr, in.nextInt());
        int m = in.nextInt();
        for(int i=0; i<m; ++i)
            sortedInsertion(0, bArr.size(), bArr, in.nextInt());

        int previous = 0;
        for(int i=0, j=0; i<bArr.size(); ++i) {
            if(j == aArr.size() || (bArr.get(i).intValue() != aArr.get(j).intValue())) {
                if(bArr.get(i) != previous) {
                    System.out.print(bArr.get(i) + " ");
                    previous = bArr.get(i);
                }
            }
            else
                ++j;
        }
    }
}
