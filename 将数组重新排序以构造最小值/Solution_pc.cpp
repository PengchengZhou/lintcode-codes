#include <cstdio>
#include <algorithm>

struct cmp{
    bool operator()(int a, int b){
        char sa[11], sb[11];
        sprintf(sa, "%d", a);
        sprintf(sb, "%d", b);
        int i=0, j=0;
        while(true){
            if(sa[i]=='\0'&&sb[j]=='\0'){
                return false; // 当两个字符串都结束，也就是按照我们的逻辑a==b的时候，返回false，否则会出错，原因不明。
            }else if(sa[i]=='\0'){
                i = 0;
            }else if(sb[j]=='\0'){
                j = 0;
            }else{
                if(sa[i]!=sb[j]){
                    return sa[i]<sb[j];
                }else{
                    i++;
                    j++;
                }
            }
        }
    }
}myCmp;

class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    string minNumber(vector<int>& nums) {
        // Write your code here
        string res = "";
        char buf[11];
        
        sort(nums.begin(), nums.end(), myCmp);
        
        for(int i=0; i<nums.size(); ++i){
            sprintf(buf, "%d", nums[i]);
            res.append(buf);
        }
        
        int j = 0;
        
        for(int i=0; i<res.size()-1; ++i){
            if(res[i]=='0'){
                j++;
            }else{
                break;
            }
        }
        
        return res.substr(j);
    }
};