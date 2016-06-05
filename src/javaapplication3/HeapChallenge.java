/*
Problem:https://www.hackerrank.com/challenges/qheap1
Insert , delete a random element from a heap, print the minimum element of a heap

@author: Meera Ramesh
email: meekar67@gmail.com


*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
class Heap{
        
        int[] priorityQueue;
        int N;
        
        Heap(int size)
            {
         priorityQueue = new int[size];  
            N=0;
        }
        public void insert(int a)
            {
            priorityQueue[++N]=a;
            swim(N);
        }
        public void delete(int key)
            {
            int i=1;
            while(i<=N)
                {
                if(priorityQueue[i]==key)
                    break;
                i++;
            }
            exch(1,i);
            deletemin();
            swimup(i);
        }
        public void swimup(int k)
        {
        	   while(k>1)
               {
               if(priorityQueue[k]<priorityQueue[k/2]) exch(k,k/2);
               
               k=k/2;
           }
        	
        }
        public void deletemin()
            {
            exch(1,N);
            N--;
            sink(1);
            //priorityQueue[N+1]=(Integer) null;
        }
        public void sink(int k)
            {
            while(2*k<=N)
                {
                int j=2*k;
                if(j<N && priorityQueue[j+1]<priorityQueue[j]) j=j+1;
                if(priorityQueue[j]<priorityQueue[k]) exch(j,k); else break;
                k=j;
            }                
        }
        public void swim(int k)
            {
            while(k>1)
                {
                if(priorityQueue[k]<priorityQueue[k/2]) exch(k,k/2);
                else break;
                k=k/2;
            }
        }
        public void exch(int j,int k)
            {
              int temp=priorityQueue[j];
            priorityQueue[j]=priorityQueue[k];
            priorityQueue[k]=temp;
        }
        public int returnMin()
            {
            return priorityQueue[1];
        }
    }
public class Solution {    
    
   
   
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner sc=new Scanner(System.in);
        int testCase = sc.nextInt();
        Heap  heap = new Heap(testCase+1);
        for(int i=0;i<testCase;i++)
            {
            int value=sc.nextInt();
            switch(value)
                {
                case 1: int insertvalue=sc.nextInt();
                        heap.insert(insertvalue);
                break;
                case 2: int deleteValue=sc.nextInt();
                        heap.delete(deleteValue);
                        break;
                case 3:System.out.println(heap.returnMin());
                break;
            }
        }
        
        
        
        
        
        
    }
}
