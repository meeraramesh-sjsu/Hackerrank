// ReverseString.cpp : Defines the entry point for the console application.
Problem: https://leetcode.com/problems/reverse-words-in-a-string/
@author: Meera Ramesh
email: meekar67@gmail.com
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void trim(string &s);
class Solution {
public:

	void reverseWords(string &s) {		
		trim(s);
		stringstream strStrr(s);
		s = "";
		recursiveReverse(strStrr,s);
		trim(s);
	}

private:
	void recursiveReverse(stringstream &input,string & result)
	{
		string word = "";
		while (input>>word)
		{
			recursiveReverse(input,result);
			result.append(word);
			if (!word.length()==0) result.append( " ");
		}
	}
};

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
int main()
{
	Solution solution;
	string s(" This is Meera ");
	solution.reverseWords(s);
    return 0;
}

