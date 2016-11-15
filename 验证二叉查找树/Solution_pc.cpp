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

// 递归验证即可，递归的时候记录最小值和最大值

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool check(TreeNode *root, int *minValue, int *maxValue){
        if(root){
            *minValue = *maxValue = root->val;
            TreeNode *left = root->left, *right = root->right;
            int leftMinValue, leftMaxValue, rightMinValue, rightMaxValue;
            if(check(left, &leftMinValue, &leftMaxValue)&&check(right, &rightMinValue, &rightMaxValue)){
                if(left&&leftMaxValue>=root->val || right&&rightMinValue<=root->val) { return false; }
                if(left) { *minValue = leftMinValue; }
                if(right) { *maxValue = rightMaxValue; }
            }else{
                return false;
            }
        }
        
        return true;
    }
    
    bool isValidBST(TreeNode *root) {
        // write your code here
        int minValue, maxValue;
        
        return check(root, &minValue, &maxValue);
    }
};