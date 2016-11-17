/*
@Problem: https://leetcode.com/problems/shuffle-an-array/
Randomnly shuffle an array using Knuth Shuffle
@author: Meera Ramesh
@email: meekar67@gmail.com
*/
class Solution {
public:
    Solution(vector<int> nums) {
        input=nums;
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
       int len = input.size();
        for(int i=len-1;i>0;i--)
        {
          int pos =rand()%(i+1);
          int temp = input[i];
          input[i] = input[pos];
          input[pos]= temp;
        }
        return input;
    }
    
private:
    vector<int> input;
    vector<int> original;
};
