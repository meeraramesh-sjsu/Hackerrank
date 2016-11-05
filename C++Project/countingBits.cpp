/*
@Problem : https://leetcode.com/problems/counting-bits/
@Author: Meera Ramesh
@email: meekar67@gmail.com
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0); 
        result.push_back(1); 
        result.push_back(1); 
        result.push_back(2);
        result.push_back(1);
        result.push_back(2);
        result.push_back(2);
        result.push_back(3);
        if(num<=7)
        {
            for(int i=7;i>num;i--)
            result.pop_back();
            return result;
        }
        for(int i=8;i<=num;i++)
        {
            if((i & (i-1))==0) result.push_back(1);
            else
            {
            int index = int(pow(2,int(log2(i))));
            result.push_back(result[index]+result[i-index]);
            }
        }
        return result;
        
    }
};