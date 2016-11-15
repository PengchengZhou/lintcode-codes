/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

// 首先将链表节点地址全部放进数组，以便随机访问
// 之后就简单了
 
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        vector<ListNode *> v;
        
        ListNode *p = head;
        while(p){
            v.push_back(p);
            p = p->next;
        }
        
        int n = v.size();
        if(!n){
            return;
        }
        
        int m = (n-1)/2;
        for(int i=0; i<=m; ++i){
            v[i]->next = n-1-i>m?v[n-1-i]:NULL;
            v[n-1-i]->next = i+1<=m?v[i+1]:NULL;
        }
    }
};
