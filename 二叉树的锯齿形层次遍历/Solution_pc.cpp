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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
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
            
            // 取出一个点
            TreeNode *now = q.front();
            q.pop();
            int layer = mp_layer[(unsigned long)now];
            if(res.size()<layer){
                res.push_back(vector<int>());
            }
            res[layer-1].push_back(now->val);
            
            // 处理与当前点在同一层次的所有点，并将当前层的所有点入栈
            stack<TreeNode *>   stk;
            stk.push(now);
            while(!q.empty()&&mp_layer[(unsigned long)q.front()]==layer){
                now = q.front();
                res[layer-1].push_back(now->val);
                stk.push(now);
                q.pop();
            }
            
            // 将下一层的点入队
            layer += 1;
            while(!stk.empty()){
                now = stk.top();
                stk.pop();
                TreeNode *left = now->left;
                TreeNode *right = now->right;
                // 如果是偶数层，则需要从右往左遍历
                if(!(layer&1)){
                    left = now->right;
                    right = now->left;
                }
                if(left){
                    mp_layer[(unsigned long)left] = layer;
                    q.push(left);
                }
                if(right){
                    mp_layer[(unsigned long)right] = layer;
                    q.push(right);
                }
            }
            
        }
        
        return res;
    }
};