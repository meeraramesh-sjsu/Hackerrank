/*
Problem: https://www.hackerrank.com/challenges/encryption
Encrypt a string of text as per row transposition cipher and print the result.

Arrange the string in rows and columns and print the columns in order.

Name: Meera Ramesh
email:meekar67#gmail.com
*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    private static int row;
    private static int col;
    private static int strLen;
    private static String inputStr;
    private static String encryptedString;
    class Node
        {
        Node next;
        char data;
    }
    class Queue
        {
        private  Node root=null;
        private Node last=null;
        
   
        public void enqueue(char a)
            {
          Node newnode= new Node();
            newnode.data=a;
            newnode.next=null;
            if(root==null)
                {
                root=last=newnode;
            }
            else
                {
                last.next=newnode;
                last=newnode;
            }
        }
        public char dequeue()
            {
            char value=root.data;
            root=root.next;
            return value;
        }
        public boolean isempty()
            {
            return root==null;
        }
    }
    public static void calRowCol()
        {
        int floorLen = (int)Math.floor(Math.sqrt(strLen));
        int ceilLen = (int)Math.ceil(Math.sqrt(strLen));
        if(floorLen == ceilLen) {row=col=floorLen;}
        else
            {
           if(floorLen * floorLen >= strLen) {
               row=col=floorLen;
               }
            else if(floorLen * ceilLen >= strLen){
                row=floorLen;
                col=ceilLen;
            }
            else {
                row = col = ceilLen;
            }
        }
    }
    public  void encryptString()
        {
       Queue queueArray[] = new Queue[col];
        for(int k=0;k<col;k++)
            {
            Queue queue=new Queue();
            queueArray[k]=queue;
        }
        int i=0;
   while(i<(strLen))
        {
        for(int j=0;j<col;j++)
            {
            if(i<strLen) {
                queueArray[j].enqueue(inputStr.charAt(i++));}
        }
        
    }
        for(int k=0;k<col;k++)
            {
            while(!queueArray[k].isempty())
                {
                System.out.print(queueArray[k].dequeue());
            }
            System.out.print(" ");
        }
    }
 
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        inputStr = in.next();
        strLen = inputStr.length();
        calRowCol();
        Solution solution = new Solution();
        solution.encryptString();
        
    }
}
