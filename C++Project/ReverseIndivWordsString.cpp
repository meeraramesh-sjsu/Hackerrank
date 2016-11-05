/*
@author: Meera Ramesh
@email: meekar67@gmail.com
@Problem: https://leetcode.com/problems/reverse-words-in-a-string/

*/
class Solution {
public:
    void reverseWords(string &s) {
            int wordCount = 0;
            int i=0;
            int len = s.size();
            int j=0;
            while(true)
            {
                while(i<len && s[i]==' ') i++;
                if(i==len) break;
                if(wordCount) s[j++] = ' ';
                int l = j;
                while(i<len && s[i]!=' ') {s[j]=s[i]; i++; j++;}
                reverseWord(s,l,j-1);
                wordCount++;
            }
            s.resize(j);
            reverseWord(s,0,j-1);
    }
private:
    void reverseWord(string &s,int i,int j)
    {
        while(i<j)
        {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
        }
    }
};