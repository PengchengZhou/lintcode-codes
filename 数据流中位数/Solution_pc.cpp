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
			��Ҫ˼·������λ��Ϊ�磬ά��������s1,s2������s1Ϊ�󶥶�,s2ΪС���ѡ�
			s1��s2���㣺
				(1) s1������Ԫ�ض�������s2�е�Ԫ��;
				(2) s2.size<=s1.size<=s2.size+1.
			s1�ĶѶ�Ԫ�ؼ�Ϊ��ǰ����λ����
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
