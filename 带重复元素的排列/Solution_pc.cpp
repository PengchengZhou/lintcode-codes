class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    void dfs(multiset<int> &nums, vector<int> tmp, vector<vector<int> > &res){
        if(nums.empty()) { res.push_back(tmp); }
        else{
            for(multiset<int>::iterator it=nums.begin(); it!=nums.end(); it++){
                vector<int> tmp1(tmp);
                tmp1.push_back(*it);

                multiset<int> nums1(nums);
                nums1.erase(nums1.find(*it));

                dfs(nums1, tmp1, res);
            }
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        multiset<int> sNums;
        for(int i=0; i<nums.size(); ++i) { sNums.insert(nums[i]); }

        vector<int> tmp;
        vector<vector<int> > tmpRes;

        dfs(sNums, tmp, tmpRes);

        sort(tmpRes.begin(), tmpRes.end());

        vector<vector<int> > res;

        for(int i=0; i<tmpRes.size(); ++i){
            if(i==0||tmpRes[i]!=tmpRes[i-1]){
                res.push_back(tmpRes[i]);
            }
        }

        return res;
    }
};