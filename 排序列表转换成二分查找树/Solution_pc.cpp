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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

// 首先将链表元素的地址存在数组里，以便随机访问
// 然后以二分的方式递归构建BST

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *buildBST(vector<ListNode *> &v, int start, int end){
        if(start>end){
            return NULL;
        }
        int mid = (start+end)>>1;
        TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
        t->val = v[mid]->val;
        t->left = buildBST(v, start, mid-1);
        t->right = buildBST(v, mid+1, end);
        
        return t;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if(!head){
            return NULL;
        }
        
        vector<ListNode *> v;
        ListNode *p = head;
        
        while(p){
            v.push_back(p);
            p = p->next;
        }
        
        int n = v.size();
        
        TreeNode *t_root = buildBST(v, 0, n-1);
        
        return t_root;
    }
};
