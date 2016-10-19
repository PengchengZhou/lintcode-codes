class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        vector<vector<int> > ret;
		
		// 将数据升序排列
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
		// 第一层for循环，枚举第1个数
        for(int i=0; i<n-3; ++i){
			// 第1个数去重
            if(i!=0&&nums[i]==nums[i-1])    continue;
            // 第二层for循环，枚举第4个数
            for(int j=n-1; j-i>=2; --j){
				// 第4个数去重
                if(j!=n-1&&nums[j]==nums[j+1])  continue;
                
				// 在[i+1,j-1]之间寻找第第2个数和第3个数，加起来等于target1
                int p = i+1, q = j-1, target1 = target-nums[i]-nums[j];
                while(p<q){
					// 相加小于target1，往右
                    if(nums[p]+nums[q]<target1) ++p;
					// 相加大于target1，往左
                    else if(nums[p]+nums[q]>target1)    --q;
					// 找到一个满足条件的解
                    else{
						// 记录结果
                        vector<int> vec = vector<int>{nums[i], nums[p], nums[q], nums[j]};
                        ret.push_back(vec);
                        
                        int k = p+1;
						// 第2个数去重
                        while(k<q&&nums[k]==nums[p])    ++k;
                        p = k;
                        k = q-1;
						// 第3个数去重
                        while(k>p&&nums[k]==nums[q])    --k;
                        q = k;
                    }
                }
            }
        }
        return ret;
    }
};
