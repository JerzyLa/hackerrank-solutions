import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Composite {
      Composite() { children = new ArrayList<Composite>(); }

      boolean isLeaf() { return children.isEmpty(); }
      int countChildren() {
         int num = children.size();
         for(Composite composite : children)
            num += composite.countChildren();

         return num;
      }

      List<Composite> children;
   }

public class Solution {

   public static int evenTree(Composite root) {
      if(root.isLeaf())
         return 0;

      int result = 0;
      for(Composite composite : root.children) {
         if(composite.countChildren() % 2 == 1)
            ++result;
         result += evenTree(composite);
      }

      return result;
   }


    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
      int parent, child;
      Scanner reader = new Scanner(System.in);
      int N = reader.nextInt();
      int M = reader.nextInt();

      List<Composite> tree = new ArrayList<Composite>();
      for(int i=0; i<N; ++i)
         tree.add(new Composite());

      for(int i=0; i<M; ++i) {
         child = reader.nextInt();
         parent = reader.nextInt();
         tree.get(parent-1).children.add(tree.get(child-1));
      }

      System.out.println(evenTree(tree.get(0)));

    }
}
