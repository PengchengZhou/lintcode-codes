#include <map>
#include <algorithm>

using namespace std;

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
     * @return: True if this Binary tree is Balanced, or false.
     */
    map<unsigned long, int> mp_addr2depth;
    bool flag = false;
    
    // dfs计算出所有树的深度
    int depth(TreeNode *root)
    {
        int ret = 0;
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        if(left)
        {
            int d_left = depth(left);
            mp_addr2depth[(unsigned long)left] = d_left;
            ret = max(ret, d_left+1);
        }
        
        if(right)
        {
            int d_right = depth(right);
            mp_addr2depth[(unsigned long)right] = d_right;
            ret = max(ret, d_right+1);
        }
        
        return mp_addr2depth[(unsigned long)root] = ret;
    }
     
    bool isBalanced(TreeNode *root) {
        // write your code here
        if(!root)   return true;
        
        if(!flag)
        {
            mp_addr2depth[(unsigned long)root] = depth(root);
            flag = true;
        }
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        if(!left&&!right)   return true;
        else if(!left)  return mp_addr2depth[(unsigned long)right]==0;
        else if(!right) return mp_addr2depth[(unsigned long)left]==0;
        else
        {
            int d_left = mp_addr2depth[(unsigned long)left];
            int d_right = mp_addr2depth[(unsigned long)right];
            
            if(abs(d_left-d_right)>1)  return false;
            
            bool ret = true;
            ret &= isBalanced(left);
            ret &= isBalanced(right);
            
            return ret;
        }
    }
};