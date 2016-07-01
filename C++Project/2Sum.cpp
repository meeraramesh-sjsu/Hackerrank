/*
https://leetcode.com/problems/two-sum/
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> unormap;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            int x = nums[i];
            if(unormap.count(target-x) > 0)
            {
                result.push_back(unormap.at(target-x));
                result.push_back(i);
            return result;
                
            }
            unormap[x]=i;
        }
        return result;
    }
};
