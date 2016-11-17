// dpMax[i]表示以nums[i]结尾的乘积最大子序列
// dpMin[i]表示以nums[i]结尾的乘积最小子序列

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        vector<int> dpMax(nums), dpMin(nums);
        
        for(int i=1; i<nums.size(); ++i){
            dpMin[i] = min(dpMin[i], min(nums[i]*dpMin[i-1], nums[i]*dpMax[i-1]));
            dpMax[i] = max(dpMax[i], max(nums[i]*dpMin[i-1], nums[i]*dpMax[i-1]));
        }
        
        int res = dpMax[0];
        for(int i=1; i<dpMax.size(); ++i) { res = max(res, dpMax[i]); }
        
        return res;
    }
};