import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Position {
    public int a;
    public int b;

    Position(int a, int b) {
        this.a = a;
        this.b = b;
    }
}

class KnightL {
    private int[][] board;
    private int count;
    private int n;

    private int countJumps(int a, int b) {
        if(a == 1 && b == 1)
            return n-1;

        count = 1;
        board = new int[n][n];
        board[0][0] = 1;

        Set<Position> startPositions = new HashSet<Position>(Arrays.asList(new Position(0,0)));
        Set<Position> newStartPositions = new HashSet<Position>();

        while(true) {
            for(Position start : startPositions) {
                Set<Position> positions = getAllPossiblePositions(a, b, start);

                Iterator<Position> it = positions.iterator();
                while(it.hasNext()) {
                    Position pos = it.next();
                    if(isFinishPositionPossibleToReached(pos))
                        return count;

                    if (isNotValidPosition(pos))
                        it.remove();
                    else
                        board[pos.a][pos.b] = 1;
                }

                newStartPositions.addAll(positions);
            }

            startPositions = newStartPositions;
            newStartPositions = new HashSet<Position>();
            if(startPositions.isEmpty())
                return -1;
            ++count;
        }
    }

    private boolean isNotValidPosition(Position pos) {
        return (pos.a < 0) || (pos.a >= n) || (pos.b >= n) || (pos.b < 0) || (board[pos.a][pos.b] != 0);
    }

    private boolean isFinishPositionPossibleToReached(Position pos) {
        return (pos.a == n-1) && (pos.b == n-1);
    }

    private HashSet<Position> getAllPossiblePositions(int a, int b, Position start) {
        return new HashSet<Position>(
                Arrays.asList(new Position(start.a + a, start.b + b), new Position(start.a + a, start.b - b),
                        new Position(start.a - a, start.b + b), new Position(start.a - a, start.b - b),
                        new Position(start.a + b, start.b + a), new Position(start.a + b, start.b - a),
                        new Position(start.a - b, start.b + a), new Position(start.a - b, start.b - a)));
    }

    public ArrayList<Integer> solve(int n) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        this.n = n;

        for(int i=1; i<n; ++i) {
            for(int j=1; j<n; ++j) {
                arr.add(countJumps(i, j));
            }
        }

        return arr;
    }

}

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        // your code goes here
        KnightL knightL = new KnightL();
        List<Integer> list = knightL.solve(n);

        for(int i=0; i<list.size(); ++i) {
            System.out.print(list.get(i) + " ");
            if((i+1)%(n-1) == 0)
                System.out.println();
        }
    }
}
