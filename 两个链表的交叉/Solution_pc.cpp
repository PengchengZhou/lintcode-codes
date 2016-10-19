/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <map> 

class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        ListNode *res = NULL;
        
        map<ListNode *, bool> mp;
        
        while(headA!=NULL){
            mp[headA] = true;
            headA = headA->next;
        }
        
        while(headB!=NULL){
            if(mp.find(headB)!=mp.end()){
                res = headB;
                break;
            }
            headB = headB->next;
        }
        
        return res;
    }
};