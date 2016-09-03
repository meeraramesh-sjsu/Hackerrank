// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//* Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
void put(ListNode* &root, int val)
 {
	 if (root == NULL) {
		root = new ListNode(val); 
		return;
	 }
	 ListNode *current = root;
	 while (current->next != NULL)
	 {
		 current = current->next;
	 }
	 current->next = new ListNode(val);
 }
// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	void inorder(TreeNode * root)
	{
		if (root == NULL) return;
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
	TreeNode *sortedListToBST(ListNode *head) {
		return build(head, NULL);
	}

	TreeNode* build(ListNode* start, ListNode* end) {
		if (start == end) {
			return NULL;
		}

		ListNode* fast = start;
		ListNode* slow = start;

		while (fast != end && fast->next != end) {
			slow = slow->next;
			fast = fast->next->next;
		}

		TreeNode* node = new TreeNode(slow->val);
		node->left = build(start, slow);
		node->right = build(slow->next, end);
		return node;
	}
	TreeNode* sortedListToBST1(ListNode* head) {
		ListNode* end = head;
		while (end->next != NULL)
		{
			end = end->next;
		}
		cout << head->val << " " << end->val << endl;
		return sortedListToBST1(head, end, NULL);
	}
private:
	TreeNode* sortedListToBST1(ListNode* start, ListNode* end, TreeNode* root)
	{
		if (start==NULL || start > end) return NULL;
		//cout << "Hello";
		ListNode *c = start, *tc = NULL, *mid = start;
		cout << start->val << " " << end->val << endl;
		if (end != NULL) {
			if (c != end) c = c->next;
			while (c != end)
			{
				tc = mid;
				mid = mid->next;
				if (c != end) c = c->next;
				if (c != end) c = c->next;
			}
		}
		root = new TreeNode(mid->val);
		cout << root->val << " ";
		root->left = sortedListToBST1(start, tc, root);
		root->right = sortedListToBST1(mid->next, end, root);
		return root;
	}
};


int main()
{
	ListNode *root = NULL;
	put(root, 1);
//	cout << root->val;
	put(root, 2);
//	cout << root->val;
	put(root, 3);
	//put(root, 8);
	//put(root, 9);
	
	ListNode* head = root;
	/*while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}*/
	Solution solution;
	TreeNode* btree = solution.sortedListToBST(root);
	solution.inorder(btree);
    return 0;
}

