/*
@Problem: https://leetcode.com/problems/top-k-frequent-elements/
@Author: Meera Ramesh
@email: meekar67@gmail.com
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
       unordered_map<int,int> aM;
        for(int i=0;i<nums.size();i++)
       {
           aM[nums[i]]++;
       }
        unordered_multimap<int,int> aRev;
       for(auto it = aM.begin();it!=aM.end();it++)
       {
          aRev.insert(pair<int,int>(it->second,it->first));
       }
       for(int i=nums.size();i>=0 && result.size()!=k ;i--)
       {
            auto at = aRev.equal_range(i);
          for(auto it = at.first; it!=at.second && result.size()!=k;++it)
           result.push_back(it->second);
       }
       return result;
    }
};