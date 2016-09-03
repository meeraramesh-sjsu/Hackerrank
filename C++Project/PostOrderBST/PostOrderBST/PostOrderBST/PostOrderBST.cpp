// PostOrderBST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//pseudo code
//1.curent = root;
//2.if current is not null, push current, current = current->right, repeat 3
//3.if current is null and stack is not empty
//pop from stack, add to vector the popped value and set it to current.
//current = current->left.go to 2.
//4.return vector.

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
template<class T>
struct Node
{
	T val;
	Node *prev;
	Node *next;
	Node(T value) :val(value), prev(NULL), next(NULL) {}
};


class Stack
{
private:
	Node<TreeNode*> *last;
public:
	Stack()
	{
		last = NULL;
	}
	bool isEmpty()
	{
		return last == NULL;
	}
	void push(TreeNode* val)
	{
		if (last == NULL)
			last = new Node<TreeNode*> (val);
		else
		{
			Node<TreeNode*> * prev = last;
			last->next = new Node<TreeNode*>(val);
			last = last->next;
			last->prev = prev;
		}
	}

	TreeNode* pop()
	{
		if (last == NULL) return NULL;
		else
		{
			TreeNode* value = last->val;
			last = last->prev;
			if(last != NULL) last->next = NULL;
			return value;
		}
	}
};

int compareTo(int a, int b)
{
	if (a < b) return -1;
	else if (a > b) return 1;
	else return 0;
}
TreeNode * put(TreeNode *root,int val)
{
	if (root == NULL) return new TreeNode(val);
	int cmp = compareTo(val, root->val);
	if (cmp < 0) root->left = put(root->left, val);
	else if (cmp > 0) root->right = put(root->right, val);
	else root->val = val;
	return root;
}

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		TreeNode *current = root;
		Stack stack;
		vector<int> vecInt;
		A: while (current != NULL)
		{
			stack.push(current);
			current = current->right;
		}
		if (current == NULL && !stack.isEmpty())
		 {
			 current = stack.pop();
			 vecInt.push_back(current->val);
			 current = current->left;
			 goto A;
		 }
		return vecInt;
	}
};
void print(int a)
{
	cout << a << " ";
}
int main()
{
	TreeNode* root = NULL;
	//root = put(root, 8);
	//root = put(root, 5);
	//root = put(root, 0);
	//root = put(root, 9);
	//root = put(root, -1);
	//root = put(root, 10);
	//root = put(root, 5);
	//root = put(root, 7);
	//root = put(root, 6);
	//root = put(root, 9);
	//root = put(root, 3);
	root = put(root, 1);
	root = put(root, 2);
	Solution solution;
	vector<int> result = solution.postorderTraversal(root);
	for_each(result.begin(), result.end(), print);
    return 0;
}
