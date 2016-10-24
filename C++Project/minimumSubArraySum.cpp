/*
@Problem: https://leetcode.com/problems/minimum-size-subarray-sum/
@author: Meera Ramesh
@e-mail: meekar67@gmail.com
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int start=0 , end = 0;
        int current_sum = 0;
        int min_length = n+1;
        while(end<n)
        {
            while(current_sum < s && end<n)
            current_sum +=nums[end++];
            
            while(current_sum >= s && start<end)
            {
                if(end - start  < min_length)
                min_length = end-start;
                
               current_sum -=nums[start++];
            }
        }
        if(min_length > n) return 0;
        return min_length;
    }
}; 