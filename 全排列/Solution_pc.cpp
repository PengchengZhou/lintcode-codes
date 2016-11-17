class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    void dfs(set<int> &nums, vector<int> tmp, vector<vector<int> > &res){
        if(nums.empty()) { res.push_back(tmp); }
        else{
            for(set<int>::iterator it=nums.begin(); it!=nums.end(); it++){
                vector<int> tmp1(tmp);
                tmp1.push_back(*it);
                
                set<int> nums1(nums);
                nums1.erase(*it);
                
                dfs(nums1, tmp1, res);
            }
        }
    }
    
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        set<int> sNums;
        for(int i=0; i<nums.size(); ++i) { sNums.insert(nums[i]); }
        
        vector<int> tmp;
        vector<vector<int> > res;
        
        dfs(sNums, tmp, res);
        
        return res;
    }
};
