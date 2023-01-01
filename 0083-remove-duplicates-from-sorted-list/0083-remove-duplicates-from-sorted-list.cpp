/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* temp = head;
        ListNode* check = NULL;
        
        while(temp != NULL)
        {
            if(check == NULL)
                check = temp;
            else
            {
                while(temp != NULL and check->val == temp->val)
                    temp = temp->next;
                check->next = temp;
                check = temp;
            }
        }
        
        return head;
    }
};