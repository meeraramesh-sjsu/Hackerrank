// StringToInteger.cpp : Defines the entry point for the console application.
//
/*
@author: Meera
email:meekar67@gmail.com

Problem:https://leetcode.com/problems/string-to-integer-atoi/
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		trim(str);
		if (isdigit(str[0]) || str[0] == '+' || str[0] == '-')
		{
			vector<int> vectorNums;
			int i = 0;
			if (str[0] == '+' || str[0] == '-') i = 1;
			for (; i < str.length() && isdigit(str[i]); i++)
				vectorNums.push_back(str[i] - '0');
			int tenVals = pow(10, vectorNums.size() - 1);
			long long result = 0;
			for (int i = 0; i < vectorNums.size(); i++)
			{
				try
				{
					result = result + vectorNums[i] * tenVals;
					tenVals = tenVals / 10;
					cout << result << " ";
					//	if (result > 2147483647)
					//	{
					//		if (str[0] == '-') return INT_MIN;
					//		else return INT_MAX;
					//	}
				}
				catch (exception ex)
				{
					//cout << ex.what();
					if (str[0] == '-') return INT_MIN;
					else return INT_MAX;
				}
			}
			int resultSi = 0;

			if (str[0] == '-') { if (-result < INT_MIN || result < INT_MIN) return INT_MIN; return -result; }
			else
			{
				if (result < 0) return INT_MAX;
				if (result > INT_MAX) return INT_MAX;

			}
			return result;
		}
		else return 0;
	}
	void trim(string &s)
	{
		std::stringstream trimmer(s);
		string result;
		s = "";
		while (trimmer >> result)
		{
			s = s + result + " ";
		}
		std::string whitespaces(" \t\f\v\n\r");

		std::size_t found = s.find_last_not_of(whitespaces);
		if (found != std::string::npos)
			s.erase(found + 1);
	}
};
int main()
{
	Solution solution;
	cout<<solution.myAtoi("2147483649");
//	cout <<endl<< INT_MAX;
	//cout << -2147483647;

	//Min -2147483647

    return 0;
}

