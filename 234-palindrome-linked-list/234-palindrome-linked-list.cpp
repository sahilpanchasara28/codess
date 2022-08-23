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
    ListNode* End(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* Reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        
        while(head != NULL)
        {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* firstEnd = End(head);
        ListNode* secondStart = Reverse(firstEnd->next);
         
        ListNode* p1 = head;
        ListNode* p2 = secondStart;
        bool ans = 1;
        
        while(ans && p2 != NULL)
        {
            if(p1->val != p2->val)
                ans = 0;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        firstEnd->next = Reverse(secondStart);
        
        return ans;
    }
};