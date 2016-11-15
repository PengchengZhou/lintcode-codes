/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 将链表的后k个元素移到前面即可
// 借助栈实现

class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        stack<ListNode*> s;
        ListNode *p = head;
        
        while(p){
            s.push(p);
            p = p->next;
        }
        
        if(s.empty()){
            return NULL;
        }
        
        k %= s.size();
        
        while(k--){
            p = s.top();
            s.pop();
            p->next = head;
            head = p;
        }
        
        if(!s.empty()){
            s.top()->next = NULL;
        }
        
        return head;
    }
};