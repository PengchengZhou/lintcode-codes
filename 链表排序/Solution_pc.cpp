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

// ���ù鲢�������������Ĺ鲢����ͬ���ǣ�����������������ʣ�
// ����ڽ��л��ֲ���֮ǰ��Ҫ�������ҵ��м�ڵ��ָ�룬
// ���ǱȻ�������Ĺ鲢����õ��ǣ��ںϲ�������ʱ����Ҫ����Ĵ洢

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *mergeSort(ListNode *start, ListNode *end){
        if(start==end){
            start->next = NULL;
            return start;
        }
        
        int cnt = 0;
        ListNode *p = start;
        
        while(true){
            cnt++;
            p = p->next;
            
            if(p==end) { break; }
        }
        
        int m = (cnt-1)>>1;
        
        p = start;
        for(int i=1; i<m; ++i) { p = p->next; }
        ListNode *l_end = p;
        p = p->next;
        ListNode *r_start = p;
        
        ListNode *l_head = mergeSort(start, l_end);
        ListNode *r_head = mergeSort(r_start, end);
        
        ListNode *p1 = l_head, *p2 = r_head;
        
        if(!p1) { return p2; }
        if(!p2) { return p1; }
        
        ListNode *head = NULL;
        
        if(p1->val<p2->val){
            head = p1;
            p1 = p1->next;
        }else{
            head = p2;
            p2 = p2->next;
        }
        
        p = head;
        while(p1&&p2){
            if(p1->val<p2->val){
                p->next = p1;
                p1 = p1->next;
            }else{
                p->next  =p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        while(p1){
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }
        while(p2){
            p->next = p2;
            p2 = p2->next;
            p = p->next;
        }
        
        return head;
    }
    
    ListNode *sortList(ListNode *head) {
        // write your code here
        if(!head) { return NULL; }
        
        ListNode *start = head, *end;
        ListNode *p = start;
        while(p->next) { p = p->next; }
        end = p;
        
        return mergeSort(start, end);
    }
};
