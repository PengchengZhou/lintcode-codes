// ±©ËÑ

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    void dfs(vector<int> &nums, int k, vector<vector<int> > &res, vector<int> tmp){
        if(k==nums.size()) { res.push_back(tmp); }
        else{
            dfs(nums, k+1, res, tmp);
            
            tmp.push_back(nums[k]);
            dfs(nums, k+1, res, tmp);
        }
    }
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
        sort(nums.begin(), nums.end());
        
        vector<vector<int> > res;
        vector<int> tmp;
        
        dfs(nums, 0, res, tmp);

        return res;
    }
};