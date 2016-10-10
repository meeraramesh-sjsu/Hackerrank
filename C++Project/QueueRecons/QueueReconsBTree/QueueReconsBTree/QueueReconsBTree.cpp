// QueueReconsBTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct Node
{
	Node *left;
	Node *right;
	int height;
	int countPer;
	int actualCount;
	Node(int value, int noofper,int real)
	{
		this->height  = value;
		countPer = noofper;
		left = NULL;
		right = NULL;
		actualCount = real;
	}
};

class BinaryTree {
public:
	void insert(int value, int countPer)
	{
		person = insert(person, value, countPer, countPer);
	}
	void inorder(Node* person,vector<pair<int, int>> & result)
	{
		if (person == NULL) return;
		inorder(person->left,result);
		cout << "{"<<person->height << " " << person->countPer << "} ";
		result.push_back({ person->height,person->actualCount });
		inorder(person->right,result);
	}
	Node* person;
	BinaryTree()
	{
		person = NULL;
		}
private:
	Node* insert(Node* person, int value, int countPer,int real)
	{
		if (person == NULL) return new Node(value, 1,real);
		if (countPer < person->countPer)
		{
			person->left = insert(person->left, value, countPer,real);
			person->countPer++;
		}
		else
		{
			person->right = insert(person->right, value, countPer - person->countPer,real);
		}
		return person;
	}
	int countOf(Node *person)
	{
		if (person == NULL) return 1;
		return person->countPer;
	}
};

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first) return p1.second < p2.second;
	return p1.first > p2.first;
}

void print(pair<int, int> vecVal)
{
	cout << "{"<< vecVal.first << " " << vecVal.second << "}";
}
class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		BinaryTree btree;
		sort(people.begin(), people.end(), compare);
		for_each(people.begin(), people.end(), print);
		cout << endl;
		for (int i = 0; i < people.size(); i++)
		{
			cout << people[i].first << " " << people[i].second << endl;
			btree.insert(people[i].first, people[i].second);
		}
		vector<pair<int, int>> result;
		btree.inorder(btree.person,result);
		return result;
	}
};

int main()
{
	Solution solution;
	vector<pair<int, int>> result;
	//[[9, 0], [7, 0], [1, 9], [3, 0], [2, 7], [5, 3], [6, 0], [3, 4], [6, 2], [5, 2]]
	result.push_back({9,0});
	result.push_back({7,0});
	result.push_back({1,9});
	result.push_back({3,0});
	result.push_back({2,7});
	result.push_back({5,3});
	result.push_back({6,0});
	result.push_back({3,4});
	result.push_back({ 6,2 });
	result.push_back({ 5,2 });
	
	vector<pair<int, int>> output;
	output = solution.reconstructQueue(result);
	 cout << endl;
	for (int i = 0; i < output.size(); i++)
		cout << "{" << output[i].first<< " " << output[i].second << "}";
    return 0;
}

