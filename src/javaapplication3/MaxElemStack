/*   
Problem: https://www.hackerrank.com/challenges/maximum-element
Insert, Delete and print maximum value of a stack.

Author: Meera
email: meekar67@gmail.com

*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
 class stack
        {
        int stack[];
        int N;
        stack(int N)
            {
            stack=new int[N];
            N=0;
        }
     boolean isempty()
         {
         return N==0;
     }
        
        void push(int a)
            {
            stack[N++]=a;
        }
        int peek()
          {
            return stack[N-1];
        }
        int pop()
            {
            return stack[--N];
        }
        
    }
public class Solution {
            
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        Solution solution = new Solution();
         stack inputstack = new stack(n);
         stack maxstack=new stack(n);
        int max=0;int input,inputvalue,deleteelem=0;
        for(int i=0;i<n;i++)
            {
            input=sc.nextInt();
            switch(input)
                {
                case 1:inputvalue=sc.nextInt();
                       inputstack.push(inputvalue);
                       if(inputvalue >= max) { max = inputvalue; maxstack.push(inputvalue);}
                       break;
                case 2:deleteelem=inputstack.peek();
                       inputstack.pop();
                if(maxstack.peek()==deleteelem) {
                    maxstack.pop();
                    if(!maxstack.isempty()) 
                        max = maxstack.peek(); else max=0;
                                                }
                       break;                
                case 3:
                System.out.println(maxstack.peek());
                       break;
                
                default: System.out.print("Enter value between 1 to 3");
                System.exit(0);
                
                break;
            }
        }
}
}
