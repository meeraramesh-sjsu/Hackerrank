/*
Problem: https://www.hackerrank.com/challenges/waiter

Group a stack of plates into different sets based on its divisibility by a primeNumber


Author:Meera Ramesh
email:meekar67@gmail.com

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
    void printstack()
        {
        for(int i=0;i<N;i++)
            System.out.println(stack[i]);
    }        
    }

public class Solution {

    static boolean isPrime(int n)
    {
    int i=3;
    while(i<=Math.ceil(Math.sqrt(n)))
        {
        if(n%i==0) return false;
        i+=2;
    }
    return true;
}
    
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
    Scanner sc = new Scanner(System.in);        
    int n=sc.nextInt();
    int q=sc.nextInt();
    int count=q;   
    stack stacknums=new stack(n);
    stack remstack=new stack(n);     
    //Fill the stack
    for(int i=0;i<n;i++)
        stacknums.push(sc.nextInt());
        int i=2;
        remstack=new stack(n);
         stack stackname=new stack(n);
         while(!stacknums.isempty())
              {
              int value=stacknums.pop();
              if(value%i==0)
                  stackname.push(value);
              else
                  remstack.push(value);
            }
         count--;
            while(!stackname.isempty())
            {
            System.out.println(stackname.pop());
        }
        stacknums=remstack;
        i=3;
    while(count>0)
        {      
        if(isPrime(i))
            {
              remstack=new stack(stacknums.N);
              stackname=new stack(n);
            while(!stacknums.isempty())
              {
              int value=stacknums.pop();
              if(value%i==0)
                  stackname.push(value);
              else
                  {
                  remstack.push(value);
              }
            }            
            count--;
            while(!stackname.isempty())
            {
            System.out.println(stackname.pop());
        }
        }
        i+=2;         
        stacknums=remstack;
    }
        while(!remstack.isempty())  
            System.out.println(remstack.pop());
        
        }
    }
