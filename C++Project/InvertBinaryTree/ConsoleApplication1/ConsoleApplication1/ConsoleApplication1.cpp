// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

/*author: Meera Ramesh
email: meekar67@gmail.com
Problem: https://leetcode.com/problems/invert-binary-tree/*/
using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int compareTo(int a, int b)
{
	if (a == b) return 0;
	else if (a < b) return -1;
	else return 1;
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
void inorder(TreeNode *root)
{
	if (root == NULL) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL) return NULL;
		TreeNode *temp = root->left;
		root->left = root->right;
		root->right = temp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}

};
ostream& operator<<(ostream& os, TreeNode *root)
{
	inorder(root);
	return os;
}
int main()
{
	TreeNode *root = new TreeNode(10);
	put(root, 7);
	put(root, 6);
	put(root, 11);
	put(root, 13);
	Solution solution;
	TreeNode *root2 = solution.invertTree(root);
	cout << root2;
    return 0;
}

