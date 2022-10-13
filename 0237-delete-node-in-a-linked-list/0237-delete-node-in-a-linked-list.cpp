/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node->next;
        ListNode* prev = node;
        
        while(curr != NULL)
        {
            prev->val = curr->val;
            if(curr->next != NULL)
                prev = curr;
            curr = curr->next;
        }
        
        prev->next = NULL;
    }
};