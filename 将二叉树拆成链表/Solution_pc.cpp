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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    
    TreeNode * dfs(TreeNode *root, TreeNode *father)
    {
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        TreeNode *tmp = root;
        if(left)    tmp = dfs(left, root);
        if(right)   tmp = dfs(right, tmp);
        
        if(father)
        {
            father->right = root;
            father->left = NULL;
        }
        
        return tmp;
    }
    
    void flatten(TreeNode *root) {
        // write your code here
        if(root)   dfs(root, NULL);
    }
};