#include <cstdio>

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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> res;
    vector<int>  path;
    
    void dfs(TreeNode *root){
        path.push_back(root->val);
        TreeNode *l_child = root->left;
        TreeNode *r_child = root->right;
        if(!l_child&&!r_child)
        {
            string tmp = "";
            for(int i=0; i!=path.size(); ++i)
            {
                int val = path[i];
                char buf[20];
                sprintf(buf, "%d", val);
                if(tmp!="") tmp.append("->");
                tmp.append(buf);
            }
            res.push_back(tmp);
        }
        if(l_child) dfs(l_child);
        if(r_child) dfs(r_child);
        path.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        if(root)    dfs(root);
        return res;
    }
};