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
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > res;
        map<unsigned long, int> mp_layer;
        if(!root){
            return res;
        }
        mp_layer[(unsigned long)root] = 1;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *now = q.front();
            q.pop();
            int layer = mp_layer[(unsigned long)now];
            if(res.size()<layer){
                res.push_back(vector<int>());
            }
            res[layer-1].push_back(now->val);
            TreeNode *left = now->left;
            TreeNode *right = now->right;
            if(left){
                mp_layer[(unsigned long)left] = layer+1;
                q.push(left);
            }
            if(right){
                mp_layer[(unsigned long)right] = layer+1;
                q.push(right);
            }
        }
        
        return res;
    }
};
