/**
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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* inorder(TreeNode *root){
        DoublyListNode *node = new DoublyListNode(root->val);
        DoublyListNode *tmp;
        if(root->left!=NULL){
            tmp = inorder(root->left);
            while(tmp->next!=NULL){
                tmp = tmp->next;
            }
            
            tmp->next = node;
            node->prev = tmp;
        }
        if(root->right!=NULL){
            tmp = inorder(root->right);
            while(tmp->prev!=NULL){
                tmp = tmp->prev;
            }
            
            tmp->prev = node;
            node->next = tmp;
        }
        
        return node;
    }
    
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        DoublyListNode *head = NULL, *tmp;
        
        if(root!=NULL){
            tmp = inorder(root);
            while(tmp->prev!=NULL){
                tmp = tmp->prev;
            }
            head = tmp;
        }
        
        return head;
    }
};