// shortestSubArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

struct Range {
	int start;
	int end;
	Range(int sts, int en)
	{
		start = sts;
		end = en;
	}
};

struct listNode {
	int index;
	int listid;
	listNode(int idx, int list)
	{
		index = idx;
		listid = list;
	}
};

struct GreaterThanByIndex {
	bool operator()(listNode a, listNode b)
	{
		return a.index > b.index;
	}
};

Range shortestSupersequence(vector<int> big, vector<int> small)
{
	vector<queue<int>> vecQue = findLocations(big, small);
	return findMinClosures(vecQue);
}
vector<queue<int>> findLocations(vector<int> big, vector<int> small)
{
	unordered_map<int, queue<int>> locations;
	for(int i=0;i<small.size();i++)
	locations[small[i]];

	for (int i = 0; i < big.size(); i++)
	{
		if (locations.count(big[i]) > 0)
			locations[big[i]].push(i);
	}
	vector<queue<int>> result;
	for (auto it = locations.begin(); it != locations.end; it++)
		result.push_back(it->second);
	return result;
}
Range findMinClosures(vector<queue<int>> vecQue)
{
	priority_queue<listNode,vector<listNode>,GreaterThanByIndex> pqlist;
	int mina = INT_MAX;
	int maxa = INT_MIN;
	for (int i = 0; i < vecQue.size(); i++)
	{
		listNode temp(vecQue[i].front(),i);
		pqlist.push(temp);
		maxa = max(maxa, vecQue[i].front());
	}
	
	listNode mini = pqlist.top;
	mina = mini.index;

	int bestmax = maxa;
	int bestmin = mina;
	while (true)
	{
		listNode mini = pqlist.top;
		mina = mini.index;
		queue<int> qt = vecQue[mini.listid];
		if (bestmax - bestmin > maxa - mina)
		{
			bestmax = maxa;
			bestmin = mina;
		}

		if (qt.size() == 0) 
			break;
		
		pqlist.pop();
		qt.pop();

		mini.index = qt.front();
		pqlist.push(mini);
		maxa = max(maxa, vecQue[mini.listid].front());
	}
	return Range(bestmin, bestmax);
}
int main()
{
	
    return 0;
}

