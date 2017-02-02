/*
@Problem: https://leetcode.com/problems/compare-version-numbers/
@author: Meera Ramesh
@email: meekar67@gmail.com
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        string temp1 = "";
        string temp2 = "";
        int i = 0;
        int j = 0;
        while(true)
        {
            while(i<version1.size() && version1[i] != '.')
            temp1 = temp1 + version1[i++];
            while(j<version2.size() && version2[j] != '.')
            temp2 = temp2 + version2[j++];
            
            int val1 = stoi(temp1);
            int val2 = stoi(temp2);
   
            if(val1 < val2) return -1;
            if(val1 > val2) return 1;
            if(i!=version1.size()) i++;
            if(j!=version2.size()) j++;
            if(j==version2.size() && i==version1.size()) return 0;
            if(i==version1.size()) 
            {
            if(stof(version2.substr(j)) == 0) return 0;    
            return -1;
            }
            if(j==version2.size()) 
            {
            if(stof(version1.substr(i)) == 0) return 0;    
            return 1;
            }
            temp1 = "";
            temp2 = "";
        }
    }
};