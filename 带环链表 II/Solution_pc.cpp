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
#include <set>
using std::set;

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        set<ListNode *> s;
        while(head){
            if(s.find(head)!=s.end()){
                return head;
            }
            s.insert(head);
            head = head->next;
        }
        return NULL;
    }
};