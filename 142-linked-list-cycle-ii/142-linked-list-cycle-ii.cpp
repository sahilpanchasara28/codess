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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head;
        ListNode *fast = head;
        bool f = 0;
        
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                f = 1;
                break;
            }
        }
        
        if(f)
        {
            slow = head;
            
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            
            return slow;
        }
        
        return NULL;
    }
};