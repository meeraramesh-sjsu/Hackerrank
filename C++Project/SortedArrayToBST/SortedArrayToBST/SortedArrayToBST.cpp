// SortedArrayToBST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode *root = NULL;
		int lo = 0;
		//cout << "size = "<< nums.size() << endl;
		int hi = nums.size() - 1;
		root = insert(nums, lo, hi, root);
		return root;
	}
	void inorder(TreeNode *root)
	{
		if (root == NULL) return;
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
private:
	TreeNode* insert(vector<int> &a, int lo, int hi, TreeNode *root)
	{
		if (lo > hi) return root;
		int mid = (lo + hi) / 2;
		root = put(root, a[mid]);
		insert(a, lo, mid - 1, root);
		insert(a, mid + 1, hi, root);
	}
	TreeNode* put(TreeNode *root, int val)
	{
		if (root == NULL) return new TreeNode(val);
		int cmp = compareTo(val, root->val);
		if (cmp < 0) root->left = put(root->left, val);
		else if (cmp > 0) root->right = put(root->right, val);
		else root->val = val;
		return root;
	}
	int compareTo(int a, int b)
	{
		if (a < b) return -1;
		else if (a > b) return 1;
		else return 0;
	}
};

int main()
{
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> vecA(a, a + 10);
	Solution solution;
	TreeNode *root = solution.sortedArrayToBST(vecA);
	solution.inorder(root);
	return 0;
}

