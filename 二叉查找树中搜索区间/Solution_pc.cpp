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

// µÝ¹éËÑË÷¼´¿É

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    void search(TreeNode *root, int k1, int k2, vector<int> &res){
        if(root){
            if(k1>root->val) { search(root->right, k1, k2, res); return; }
            if(k2<root->val) { search(root->left, k1, k2, res); return; }
            
            search(root->left, k1, root->val, res);
            res.push_back(root->val);
            search(root->right, root->val, k2, res);
        }
    }
    
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> res;
        
        search(root, k1, k2, res);
        
        return res;
    }
};