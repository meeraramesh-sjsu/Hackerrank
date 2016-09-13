// MajorityElement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<map>
#include<iostream>
#include<vector>

/*
@author: Meera Ramesh
@email: meekar67@gmail.com
Problem: https://leetcode.com/submissions/detail/74170293/
*/
using namespace std;
class Solution {
public:
	/*Solution 1*/
	int majorityElement(vector<int>& nums) {
		int major = nums[0], count = 1;
		for (int i = 1; i<nums.size(); i++)
		{
			if (count == 0)
			{
				major = nums[i];
				count = 1;
			}
			else if (major == nums[i]) count++;
			else count--;
		}
		return major;
	}
};

int main()
{
	vector<int> a = { 0,1,1,2 };
	Solution solution;
	cout<< solution.majorityElement(a);
    return 0;
}

