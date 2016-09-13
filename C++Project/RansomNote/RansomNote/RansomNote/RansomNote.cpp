// RansomNote.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/*
#author: Meera Ramesh
email: meekar67@gmail.com
Problem: https://leetcode.com/problems/ransom-note/
*/
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int charIdx[26] = { 0 };
		int count = 0;
		for (int i = 0; i<magazine.size(); i++)
		{
			charIdx[magazine[i] - 'a']++;
		}
		for (int i = 0; i<ransomNote.size(); i++)
		{
			if (charIdx[ransomNote[i] - 'a'] > 0)
			{
				charIdx[ransomNote[i] - 'a']--;
				count++;
			}
			else return false;
		}
		return true;
	}
};

int main()
{
	Solution solution;
	cout << solution.canConstruct("aabb", "abababaa");
    return 0;
}

