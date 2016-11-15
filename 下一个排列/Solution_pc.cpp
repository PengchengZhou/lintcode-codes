// 主要思路是从右往左扫描，找到第一个违反从右往左递增序的元素
// 然后将该元素与从右往左第一个比它大的元素交换
// 最后将后续元素升序排列

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        
        int i2 = nums.size()-1, i1 = -1;
        
        for(int i=nums.size()-2; i>=0; --i){
            if(i+1<=nums.size()&&nums[i]<nums[i+1]){
                i1 = i;
                while(nums[i1]>=nums[i2]){
                    i2--;
                }
                
                break;
            }
        }
        
        if(i1>=0&&i2>=i1){
            int tmp = nums[i1];
            nums[i1] = nums[i2];
            nums[i2] = tmp;
            
            sort(nums.begin()+i1+1, nums.end());
            
            return nums;
        }else{
            vector<int> res;
            for(int i=nums.size()-1; i>=0; --i){
                res.push_back(nums[i]);
            }
            
            return res;
        }
    }
};