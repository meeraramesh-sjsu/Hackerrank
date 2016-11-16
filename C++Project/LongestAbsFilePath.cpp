/*
@Problem: https://leetcode.com/problems/longest-absolute-file-path/
@author: Meera
@email: meekar67@gmail.com
*/
class Solution {
public:
    int lengthLongestPath(string input) {
        int i = 0;
        int j=0;
        list<string> parent;
        int parentVal=0;
        int parentLen = 0;
        int maxLen = 0;
        while(i<input.size())
        {
            formParent(input,i,parent,parentVal,parentLen,maxLen);
            j=i;
            while(input[j]=='\n'||input[j]=='\t') j++;
            parentVal=j-i-1;
            i=j;
        }
       if(maxLen==0) return 0;
        return maxLen - 1;
    }
private:
    void formParent(string input,int &index,list<string>& parent,int parentVal,int &parentLen,int &maxLen) {
        string parentCur="";
        while(parentVal!=parent.size()) { parentLen = parentLen - parent.back().size() - 1; parent.pop_back();}
        while(input[index]!='\n' && index<input.size())
        {
            parentCur=parentCur+input[index++];
         }
         parentLen = parentLen + parentCur.size() + 1;
        parent.push_back(parentCur);
        if(parent.back().find('.')!=string::npos) {if(maxLen < parentLen) maxLen = parentLen;}
    }
};