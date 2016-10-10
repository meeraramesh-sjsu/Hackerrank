// QueueRecons.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(std::pair<int, int> &left)
{
	cout << "{" << left.first << " " << left.second << "}";
}

class Solution {
public:

	vector<pair<int,int>> reconstructQueue(vector<pair<int,int>>& people) {
		//sort(people.begin(), people.end(), sort_pred());
		sort(people.begin(), people.end(), sort_pred_2());
		for_each(people.begin(), people.end(), print);
		vector<pair<int, int>>::iterator it=people.begin();
		vector<pair<int, int>>::iterator itTemp;
		int i = 0;
		while (it != people.end())
		{
			int j = i - 1;
			if ((i >= it->second)) {
				cout << "it->second= " << it->second << " i= " << i << endl;
					it++; i++; continue;
			}
			cout << " not correct i=" << i << endl;
			int index = it->second;
			people.insert(people.begin()+index,*it);
			if (i == people.size() - 1) break;
			people.erase(people.begin()+i);
			it = people.begin() + i++;
		}
		return people;
	}

private:
	
	struct sort_pred {
		bool operator()(const std::pair<int, int> &left, const std::pair<int, int> &right) {
			return left.first < right.first;
		}
	};
	struct sort_pred_2 {
		bool operator()(const std::pair<int, int> &left, const std::pair<int, int> &right) {
			return left.second < right.second;
		}
	};
};

int main()
{
	vector<pair<int, int>> people;
	people.push_back({ 7, 0 });
	people.push_back({ 4, 4 });
	people.push_back({ 7, 1 });
	people.push_back({ 5, 0 });
	people.push_back({ 6, 1 });
	people.push_back({ 5, 2 });

	Solution solution;
	vector<pair<int, int>> result = solution.reconstructQueue(people);
	cout << endl;
	for_each(result.begin(), result.end(), print);
    return 0;
}

