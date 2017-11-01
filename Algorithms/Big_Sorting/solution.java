import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class StringComparator implements Comparator<String> {
    public int compare(String s1, String s2) {
        if(s1.length() > s2.length())
            return 1;
        else if(s1.length() < s2.length())
            return -1;

        return s1.compareTo(s2);
    }
}

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String[] unsorted = new String[n];
        for(int unsorted_i=0; unsorted_i < n; unsorted_i++){
            unsorted[unsorted_i] = in.next();
        }
        // your code goes here
        Collections.sort(Arrays.asList(unsorted), new StringComparator());
        for(String el : unsorted)
            System.out.println(el);
    }
}
