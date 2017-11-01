import java.io.*;
import java.util.*;

class ConnectedCellsInAGrid {
    boolean[][] seen;
    int[][] nodes;
    int n;
    int m;

    public int visitNode(int i, int j) {
        seen[i][j] = true;
        if(nodes[i][j] == 0)
            return 0;

        /// check all unseen neighbours.
        int result = 1;
        if(i>0 && j>0 && seen[i-1][j-1]==false)
            result += visitNode(i-1, j-1);
        if(i>0 && seen[i-1][j]==false)
            result += visitNode(i-1, j);
        if(i>0 && j<m-1 && seen[i-1][j+1]==false)
            result += visitNode(i-1, j+1);

        if(j>0 && seen[i][j-1]==false)
            result += visitNode(i, j-1);
        if(j<m-1 && seen[i][j+1]==false)
            result += visitNode(i, j+1);

        if(i<n-1 && j>0 && seen[i+1][j-1]==false)
            result += visitNode(i+1, j-1);
        if(i<n-1 && seen[i+1][j]==false)
            result += visitNode(i+1, j);
        if(i<n-1 &&  j<m-1 && seen[i+1][j+1]==false)
            result += visitNode(i+1, j+1);

        return result;
    }

    public int solve(int[][] nod, int n, int m) {
        seen = new boolean[n][m];
        nodes = nod;
        this.n = n;
        this.m = m;
        int result = 0;

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(seen[i][j] == false)
                    result = Math.max(result, visitNode(i, j));
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
        int m = in.nextInt();
        int[][] nodes = new int[n][m];

        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                nodes[i][j] = in.nextInt();

        ConnectedCellsInAGrid connectedCellsInAGrid = new ConnectedCellsInAGrid();
        System.out.println(connectedCellsInAGrid.solve(nodes, n, m));
    }
}
