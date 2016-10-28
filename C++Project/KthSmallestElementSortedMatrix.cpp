/*
@Problem: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
@author: Meera Ramesh
@email: meekar67@gmail.com
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
     int n = matrix.size();
     int left = matrix[0][0];
     int right = matrix[n-1][n-1];
     while(left<right)
     {
         int mid = (left + right)/2;
         int j = n-1;
        int count = 0;
        for(int i=0;i<n;i++)
        {
      //      int j=n-1;
        while(j>=0 && matrix[i][j]>mid)
        j--;
        count +=j+1;
        }
        if(count < k)
        left = mid + 1;
        else 
        right = mid;
     }
     return left;
    }
};