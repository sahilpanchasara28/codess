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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *prev=head;
        ListNode *current=head;
        int count=n;
        while(current !=NULL && count!=0)
        {
            current=current->next;
            count--;
        }     
        if(current==NULL && count==0)
        {
            return prev->next;
        }
        while(current->next!=NULL)
        {
            prev=prev->next;
            current=current->next;
        }
        prev->next=prev->next->next;
        return head;
        
    }
};