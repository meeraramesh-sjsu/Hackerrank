package javaapplication3;

import java.util.Scanner;
import java.util.Stack;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Meera
 * @email meekar67@gmail.com
 */
public class simple_text_editor {
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int noOfOptions=sc.nextInt();
        Stack<String> stk=new Stack<>();
        String s_input=new String();
        for(int i=0;i<noOfOptions;i++)
        {
            int input=sc.nextInt();
            stk.push("");
            switch(input)
            {
                case 1:
                       String append=sc.nextLine().trim();
                       s_input=s_input + append;
                        stk.push(s_input); 
                       break;  
                case 2:
                       int k=sc.nextInt();
                       
                       int start=s_input.length() - k;
                      String temp = null;
                      temp=s_input.substring(0, start);
                       s_input=temp;
                    
                       stk.push(s_input);
                       break;  
                case 3:
                       int kprint=sc.nextInt();
                       char inputchar[]=s_input.toCharArray();
                        System.out.println(inputchar[kprint-1]);
                       break;     
                case 4:
                       stk.pop();
                       s_input=stk.peek();
                       break; 
                default:
                       System.out.print("Please enter options between 1 and 4");
                       System.exit(0);
            }
        }
    }
}