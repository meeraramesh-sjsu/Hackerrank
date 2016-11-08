/*
Name: Meera Ramesh
e-mail: meekar67@gmail.com
Problem: https://leetcode.com/problems/sort-characters-by-frequency/

*/
struct compareTo
{
    bool operator()(string a, string b) 
    {
        return a.size() > b.size();
    }
};
class Solution {
public:
    string frequencySort(string s) {
        struct compareTo comp;
        if(s.size()==0) return "";
        vector<string> inputArray(128);
        for(int i=0;i<s.size();i++)
        {
           inputArray[s[i]] += s[i];
          }
        sort(inputArray.begin(),inputArray.end(),comp);
        while(inputArray.back().size() == 0)
        inputArray.pop_back();
        string result = "";
        for(int i=0;i<inputArray.size();i++)
        {
        result += inputArray[i];
        }
        return result;
    }
};