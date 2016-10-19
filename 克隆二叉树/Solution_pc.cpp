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
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
        // Write your code here
        TreeNode *root_cpy = NULL;
        if(root!=NULL){
            root_cpy = new TreeNode(root->val);
            root_cpy->left = cloneTree(root->left);
            root_cpy->right = cloneTree(root->right);
        }
        return root_cpy;
    }
};