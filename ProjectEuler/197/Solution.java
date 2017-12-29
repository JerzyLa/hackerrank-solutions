import java.io.*;
import java.util.*;

public class Solution {
  public static double solution(double u, double b)
  {
    final long div = 1000000000;
    double prev_x = 0.0, x = 0.0, next_x = 0.0;
    x = u;

    for(int i=1; i<div; ++i)
    {
      next_x = Math.floor(Math.pow(2, (b-x*x))) / div;
      if((i>3) && (Math.abs(next_x - x) < 0.000000001 || Math.abs(prev_x - next_x) < 0.000000001 ))
        return next_x + x;

      prev_x = x;
      x = next_x;
    }

    return -1.0;
  }

  public static void main(String[] args) {
      Scanner in = new Scanner(System.in);
      double u = in.nextDouble();
      double b = in.nextDouble();

      System.out.printf("%.9f\n", solution(u,b));
  }
}
