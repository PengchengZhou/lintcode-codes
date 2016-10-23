#include <set>
using std::multiset;

struct Comp{
    bool operator()(const int &a, const int &b)const
    { return a>b; }
};

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> maxNums;
        
		/*
			思路：用一个大顶堆来维护最大值即可。
		*/
        multiset<int, Comp> s;
        for(int i=0; i<nums.size()&&i<k; ++i){
            s.insert(nums[i]);
        }
        if(s.size()){
            maxNums.push_back(*(s.begin()));
        }
        
        for(int i=0, j=k; j<nums.size(); ++i, ++j){
            s.erase(s.find(nums[i]));
            s.insert(nums[j]);
            maxNums.push_back(*(s.begin()));
        }
        
        return maxNums;
    }
};
