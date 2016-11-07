class Solution {
private:
    void swap(vector<int> &nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
		// ���������黮�ֵ�˼��
        int i=-1, j=0;
        while(i<=j&&j<nums.size()){
            if(nums[j]>=k){
                j++;
            }else{
                i++;
                swap(nums, i, j);
                j++;
            }
        }
        return i+1;
    }
};