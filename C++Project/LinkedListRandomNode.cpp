/*
@Problem: https://leetcode.com/problems/linked-list-random-node/
@Author: Meera Ramesh
@E-mail :meekar67@gmail.com

*/
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
         root = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int result = root->val;
        ListNode *current = root;
        for(int i=0;current!=NULL;i++)
        {
            if(rand()%(i+1) == i)
            result = current->val;
            current = current->next;
        }
        return result;
    }
    private:
    ListNode *root;
};
