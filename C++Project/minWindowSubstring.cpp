/*
@author: Meera Ramesh
@Problem: https://leetcode.com/problems/minimum-window-substring/
@email: meekar67@gmail.com
*/
#include <string>
#include <iostream>
#include <climits>
#include <stdint.h>

using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int needToFind[256]={0};
        int hasFound[256]={0};
        int count = 0;
        int minWindowBegin = -1;
        int minWindowEnd=-1;
        int minWindowLength = INT_MAX;
        int slen = s.size();
        int tlen = t.size();
        for(int i=0;i<tlen;i++)
        	needToFind[t[i]]++;
    	int begin = 0;
    	int end = 0;
    	for(;end<slen;end++)
    	{
    			if(needToFind[s[end]]==0) continue;
    				hasFound[s[end]]++;
    			if(hasFound[s[end]]<=needToFind[s[end]])
    	    	count++;
        		if(count==tlen)
    			{
    				while(needToFind[s[begin]]==0 || hasFound[s[begin]]>needToFind[s[begin]])
    				{
    					hasFound[s[begin]]--;
    					begin++;
    				}
    			if(end-begin+1 < minWindowLength)
    			{
    				minWindowBegin = begin;
    				minWindowLength = end-begin+1;
    				minWindowEnd = end;
    			}
    			}
    	}
    	if(minWindowLength==INT_MAX) return "";
    	return s.substr(minWindowBegin,minWindowLength);
        }
};
