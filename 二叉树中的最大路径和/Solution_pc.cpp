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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int res;
    
    int dfs(TreeNode *root){
        if(!root)   return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int ret1 = 0, ret2 = 0;
        if(left)    ret1 = dfs(left);
        if(right)   ret2 = dfs(right);
        
        if(ret1<0)  ret1 = 0;
        if(ret2<0)  ret2 = 0;
        
        res = max(res, ret1+ret2+root->val);
        
        int ret = max(ret1, ret2);
        ret += root->val;
        return ret;
    }
    
    int maxPathSum(TreeNode *root) {
        // write your code here
        
        res = -0x7fffffff;
        dfs(root);
        return res;
    }
};