// Ö±½ÓµÝ¹éËÑË÷¼´¿É

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    
    void dfs(int a, int b, int k, vector<int> v, vector<vector<int> > &res){
        if(k==0){
            res.push_back(v);
            return;
        }
        
        for(int i=a; i<=b-k+1; i++){
            vector<int> v1(v);
            v1.push_back(i);
            dfs(i+1, b, k-1, v1, res);
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int> > res;
        
        vector<int> v;
        dfs(1, n, k, v, res);
        
        return res;
    }
};