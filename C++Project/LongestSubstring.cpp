// longestSubStr.cpp : Defines the entry point for the console application.

@Name: Meera Ramesh
@Email: meekar67@gmail.com
@Problem: https://leetcode.com/submissions/detail/66635008/
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int charArray[128];
		memset(charArray, -1, sizeof(charArray));
		int k = 0;
		trim(s);
		string temp = "";
		int N = s.length();
		int result = 0;
			for (int i = 0; i < N; i++)
		{
			//cout << 2;
			int index = s[i];
			if (charArray[index] == -1)
			{
				charArray[index] = i;
			}
			else
			{
			    temp = s.substr(k, i - k);			
				if (temp.length() > result)
					result = temp.length();
				 k = charArray[index]+1;
				 i = k - 1;
				memset(charArray, -1, sizeof(charArray));
			}
		}
		if (k < N) temp = s.substr(k, N-k);
		if (temp.length() > result) result = temp.length();
		if (temp.length() == 0) result= N;
		return result;
	}
private:
	void trim(string &input)
	{
		stringstream s(input);
		string temp = "";
		input = "";
		while (s >> temp)
		{
			input = input + temp;
			input = input + " ";
		}
		if(input.length()!=0) input.pop_back();
	}
};
int main()
{
	Solution solution;
	cout<<solution.lengthOfLongestSubstring("ABCDabcd");
	return 0;
}

