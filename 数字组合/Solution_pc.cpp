// 递归搜索，一个一个的选即可

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    void dfs(vector<int> &candidates, int i, int target, vector<int> v, vector<vector<int> > &res){
        if(i>=candidates.size()){
            if(target==0){
                sort(v.begin(), v.end());
                res.push_back(v);
            }
            return;
        }
        
        if(target==0){
            sort(v.begin(), v.end());
            res.push_back(v);
            return;
        }
        
        for(int j=0; candidates[i]*j<=target; ++j){
            vector<int> v1(v);
            for(int k=0; k<j; ++k) { v1.push_back(candidates[i]); }
            dfs(candidates, i+1, target-candidates[i]*j, v1, res);
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int> > res;
        
        if(candidates.size()){
            sort(candidates.begin(), candidates.end());
            vector<int> candidates_no_repeat;
            candidates_no_repeat.push_back(candidates[0]);
            
            for(int i=1; i<candidates.size(); ++i){
                if(candidates[i]!=candidates[i-1]){
                    candidates_no_repeat.push_back(candidates[i]);
                }
            }
            
            vector<int> v;
            dfs(candidates_no_repeat, 0, target, v, res);
        }
        
        return res;
    }
};