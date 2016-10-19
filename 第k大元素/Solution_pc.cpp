class Solution {
private:
    void swap(vector<int> &nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    int findKthLargest(vector<int> &nums, int l, int r, int k){
        if(l==r){
            return nums[l];
        }
        int i=l-1, j=l;
        while(j<r){
            if(nums[j]>nums[r]){
                swap(nums, ++i, j);
            }
            j++;
        }
        swap(nums, ++i, r);
        if(i==k){
            return nums[i];
        }
        if(i>k){
            return findKthLargest(nums, l, i-1, k);
        }
        if(i<k){
            return findKthLargest(nums, i+1, r, k);
        }
    }

public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        return findKthLargest(nums, 0, nums.size()-1, k-1);
    }
};