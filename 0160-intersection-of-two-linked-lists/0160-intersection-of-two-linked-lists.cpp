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
    
    int len(ListNode* head)
    {
        int ans = 0;
        ListNode* temp = head;
        
        while(temp != NULL)
        {
            temp = temp->next;
            ans++;
        }
        
        return ans;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lenA = len(headA);
        int lenB = len(headB);
        
        int diff = 0;
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        if(lenA < lenB)
        {
            diff = lenB - lenA;
            
            while(diff--)
                temp2 = temp2->next;
        }
        else if(lenA > lenB)
        {
            diff = lenA - lenB;
            
            while(diff--)
                temp1 = temp1->next;
        }
        
        ListNode* ans = NULL;
        
        while(temp1 != NULL and temp2 != NULL)
        {
            if(temp1 == temp2)
            {
                ans = temp1;
                break;
            }
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return ans;
    }
};