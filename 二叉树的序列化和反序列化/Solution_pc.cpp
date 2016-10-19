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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        if(!root)   return "#";
        string res = "";
        char buf[100];
        sprintf(buf, "%d", root->val);
        res.append(string(buf));
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *now = q.front();
            q.pop();
            TreeNode *left = now->left;
            TreeNode *right = now->right;
            if(!left){
                res.append(",#");
            }else{
                sprintf(buf, "%d", left->val);
                res.append(",");
                res.append(string(buf));
                q.push(left);
            }
            if(!right){
                res.append(",#");
            }else{
                sprintf(buf, "%d", right->val);
                res.append(",");
                res.append(string(buf));
                q.push(right);
            }
        }
        
        return res;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        if(data[0]=='#')    return NULL;
        deque<string> q;
        while(true){
            int pos = data.find_last_of(',');
            if(pos==string::npos){
                q.push_front(data);
                break;
            }
            q.push_front(data.substr(pos+1));
            data.erase(pos);
        }
        
        string s = q.front();
        q.pop_front();
        TreeNode *root = new TreeNode(atoi(s.c_str()));
        queue<TreeNode *> q1;
        q1.push(root);
        while(!q1.empty()){
            TreeNode *now = q1.front();
            q1.pop();
            s = q.front();
            q.pop_front();
            if(s[0]!='#'){
                now->left = new TreeNode(atoi(s.c_str()));
                q1.push(now->left);
            }
            s = q.front();
            q.pop_front();
            if(s[0]!='#'){
                now->right = new TreeNode(atoi(s.c_str()));
                q1.push(now->right);
            }
        }
        
        return root;
    }
};
