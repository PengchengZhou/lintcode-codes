/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <map>

class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        RandomListNode *head_cpy = NULL;
        
        if(head!=NULL){
            head_cpy = new RandomListNode(head->label);
            
            map<RandomListNode*, RandomListNode*> p_map;
            p_map[head] = head_cpy;
            
            RandomListNode *tmp = head, *tmp1 = head_cpy;
            while(tmp->next!=NULL){
                tmp = tmp->next;
                tmp1->next = new RandomListNode(tmp->label);
                tmp1 = tmp1->next;
                
                p_map[tmp] = tmp1;
            }
            
            tmp = head;
            tmp1 = head_cpy;
            while(tmp!=NULL){
                tmp1->random = p_map[tmp->random];
                tmp = tmp->next;
                tmp1 = tmp1->next;
            }
        }
        
        return head_cpy;
    }
};