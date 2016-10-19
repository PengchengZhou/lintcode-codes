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
            
            // ȡ��һ����
            TreeNode *now = q.front();
            q.pop();
            int layer = mp_layer[(unsigned long)now];
            if(res.size()<layer){
                res.push_back(vector<int>());
            }
            res[layer-1].push_back(now->val);
            
            // �����뵱ǰ����ͬһ��ε����е㣬������ǰ������е���ջ
            stack<TreeNode *>   stk;
            stk.push(now);
            while(!q.empty()&&mp_layer[(unsigned long)q.front()]==layer){
                now = q.front();
                res[layer-1].push_back(now->val);
                stk.push(now);
                q.pop();
            }
            
            // ����һ��ĵ����
            layer += 1;
            while(!stk.empty()){
                now = stk.top();
                stk.pop();
                TreeNode *left = now->left;
                TreeNode *right = now->right;
                // �����ż���㣬����Ҫ�����������
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