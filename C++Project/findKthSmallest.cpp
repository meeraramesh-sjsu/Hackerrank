/*
@Problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
@author: Meera Ramesh
@email: meekar67@gmail.com
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        int index = 0;
        inorder(root,k,result);
        return result;
    }
    void inorder(TreeNode *root, int & k,int & result)
    {
        if(root==NULL) return;
        inorder(root->left,k,result);
        if(--k==0) result = root->val;
        inorder(root->right,k,result);
    }
};