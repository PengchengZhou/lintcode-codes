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
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> medians;
        
		/*
			主要思路：以中位数为界，维护两个堆s1,s2。其中s1为大顶堆,s2为小顶堆。
			s1和s2满足：
				(1) s1中所有元素都不大于s2中的元素;
				(2) s2.size<=s1.size<=s2.size+1.
			s1的堆顶元素即为当前的中位数。
		*/
        multiset<int, Comp> s1;
        multiset<int> s2;
        for(int i=0; i<nums.size(); ++i){
            if(s1.size()==0){
                s1.insert(nums[i]);
            }else if(s1.size()==s2.size()){
                s2.insert(nums[i]);
                int tmp = *(s2.begin());
                s2.erase(s2.begin());
                s1.insert(tmp);
            }else{
                int tmp = *(s1.begin());
                s1.erase(s1.begin());
                s2.insert(tmp);
                s2.insert(nums[i]);
                tmp = *(s2.begin());
                s2.erase(s2.begin());
                s1.insert(tmp);
            }
            
            medians.push_back(*(s1.begin()));
        }
        
        return medians;
    }
};
