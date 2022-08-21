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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(-1000);
        ListNode* h = ans;
        
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        
        while(h1 != NULL && h2 != NULL)
        {
            if(h1->val > h2->val)
            {
                ans->next = h2;
                ans = h2;
                h2 = h2->next;
            }
            else
            {
                ans->next = h1;
                ans = h1;
                h1 = h1->next;
            }
        }
        
        while(h1 != NULL)
        {
            ans->next = h1;
            ans = h1;
            h1 = h1->next;
        }
        
        while(h2 != NULL)
        {
            ans->next = h2;
            ans = h2;
            h2 = h2->next;
        }
        
        return h->next;
    }
};