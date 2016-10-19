#include <map>
#include <set>

using std::map;
using std::set;

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
private:
    map<TreeNode *, TreeNode *> parent;
    
    void dfs(TreeNode *root){
        if(root->left!=NULL){
            parent[root->left] = root;
            dfs(root->left);
        }
        if(root->right!=NULL){
            parent[root->right] = root;
            dfs(root->right);
        }
    }
    
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        parent[root] = NULL;
        dfs(root);
        set<TreeNode *> s;
        TreeNode *tmp = A;
        while(tmp!=NULL){
            s.insert(tmp);
            tmp = parent[tmp];
        }
        tmp = B;
        while(tmp!=NULL){
            if(s.find(tmp)!=s.end()){
                return tmp;
            }else{
                tmp = parent[tmp];
            }
        }
    }
};