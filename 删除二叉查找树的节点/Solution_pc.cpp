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

// ��Ҫ˼·��
//     ��1���ҵ�Ҫɾ���Ľڵ�
//     ��2�����������Ϊ�գ������������������
//          ���������Ϊ�գ������������������
//          ���������������Ϊ�գ����������е����ֵ������ǰ�ڵ㣬���ݹ�doRemoveNode.

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode *findMin(TreeNode *root, TreeNode **parent){
        while(root->left) { *parent = root; root = root->left; }
        return root;
    }
    TreeNode *findMax(TreeNode *root, TreeNode **parent){
        while(root->right) { *parent = root; root = root->right; }
        return root;
    }
    
    TreeNode *doRemoveNode(TreeNode *root, int value, TreeNode *parent, bool flag){
        TreeNode *res = root;
        
        if(root){
            if(root->val==value){
                if(!root->left){
                    if(parent==NULL) { return root->right; }
                    if(flag) { parent->left = root->right; }
                    else { parent->right = root->right; }
                    return res;
                }
                if(!root->right){
                    if(parent==NULL) { return root->left; }
                    if(flag) { parent->left = root->left; }
                    else { parent->right = root->left; }
                    return res;
                }
                
                TreeNode *t_parent = root;
                TreeNode *tmp = findMax(root->left, &t_parent);
                root->val = tmp->val;
                if(tmp->left||tmp->right) { doRemoveNode(tmp, tmp->val, t_parent, false); }
                if(!tmp->left&&!tmp->right) {
                    if(t_parent==root) { t_parent->left = NULL; }
                    else { t_parent->right = NULL; }
                }
                
            }else if(value<root->val){
                doRemoveNode(root->left, value, root, true);
            }else{
                doRemoveNode(root->right, value, root, false);
            }
        }
        
        return res;
    }
    
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if(root){
            if(root->val==value){
                if(!root->left) { return root->right; }
                if(!root->right) { return root->left; }
                
                TreeNode *t_parent = root;
                TreeNode *tmp = findMax(root->left, &t_parent);
                root->val = tmp->val;
                if(tmp->left||tmp->right) { doRemoveNode(tmp, tmp->val, t_parent, false); }
                if(!tmp->left&&!tmp->right) {
                    if(t_parent==root) { t_parent->left = NULL; }
                    else { t_parent->right = NULL; }
                }
                
            }else if(value<root->val){
                doRemoveNode(root->left, value, root, true);
            }else{
                doRemoveNode(root->right, value, root, false);
            }
        }
        
        return root;
    }
};