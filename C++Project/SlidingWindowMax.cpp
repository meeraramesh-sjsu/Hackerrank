/*
@author: Meera Ramesh
Problem: https://leetcode.com/problems/sliding-window-maximum/
e-mail: meekar67@gmail.com
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         vector<int> result;
        if(nums.size()==0) return result;
        if(k==0) return nums;
       deque<int> maxEle;
       int maxPos = 0;
       int i=0;
       int n=nums.size();
       for(;i<k;i++)
       {
           while(!maxEle.empty() && nums[i]>=nums[maxEle.back()])
           maxEle.pop_back();
           maxEle.push_back(i);
       }
       for(;i<n;i++)
       {
           result.push_back(nums[maxEle.front()]);
           while(!maxEle.empty() && maxEle.front()<=i-k)
           maxEle.pop_front();
           while(!maxEle.empty() && nums[i]>=nums[maxEle.back()])
           maxEle.pop_back();
           maxEle.push_back(i);
       }
       result.push_back(nums[maxEle.front()]);
       return result;
    }
};