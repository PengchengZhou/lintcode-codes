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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    void dfs(vector<vector<int>> &results, vector<int> &tmp, TreeNode *root, int target){
        if(root!=NULL){
            tmp.push_back(root->val);
            target -= root->val;
            if(root->left==NULL&&root->right==NULL&&target==0){
                vector<int> path;
                for(int i=0; i<tmp.size(); ++i){
                    path.push_back(tmp[i]);
                }
                results.push_back(path);
            }else{
                dfs(results, tmp, root->left, target);
                dfs(results, tmp, root->right, target);
            }
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<vector<int>> results;
        vector<int> tmp;
        
        dfs(results, tmp, root, target);
        
        return results;
    }
};