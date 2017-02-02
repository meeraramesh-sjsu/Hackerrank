/*
@Problem: https://leetcode.com/problems/first-unique-character-in-a-string/
O(n) approach and constant space
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> unmap;
        for(int i=0;i<s.size();i++)
        {
            if(unmap.count(s[i]) > 0)
            {
                if(unmap.find(s[i])->second == -1)
                continue;
                else unmap[s[i]] = -1;
            }
            else unmap[s[i]] = i;
        }
        int minVal = INT_MAX;
         for (std::unordered_map<char,int>::iterator it=unmap.begin(); it!=unmap.end(); ++it)
       {
        if(it->second < minVal && it->second !=-1) minVal = it->second;
        }
        return (minVal == INT_MAX) ?-1:minVal;
    }
};