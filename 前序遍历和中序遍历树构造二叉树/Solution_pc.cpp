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
 
#include <map>
map<int, int> idx;
int pre_i;

class Solution {
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
private:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int left, int right){
        if(pre_i>=preorder.size()||left>right){
            return NULL;
        }
        
        TreeNode *rt = new TreeNode(preorder[pre_i]);
        
        int j = idx[preorder[pre_i]];
        
        pre_i++;
        
        rt->left = build(preorder, inorder, left, j-1);
        rt->right = build(preorder, inorder, j+1, right);
        
        return rt;
    }
    
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        int n = preorder.size();
        
        idx.clear();
        for(int i=0; i<n; ++i){
            idx[inorder[i]] = i;
        }
        
        pre_i = 0;
        return build(preorder, inorder, 0, n-1);
    }
};