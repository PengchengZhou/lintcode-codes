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
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        ListNode *pre = NULL;
        ListNode *now = head;
        ListNode *next;
        
        while(now)
        {
            next = now->next;
            if(next)
            {
                now->next = next->next;
                next->next = now;
                if(now==head)   head = next;
                if(pre) pre->next = next;
            }
            pre = now;
            now = now->next;
        }
        
        return head;
    }
};