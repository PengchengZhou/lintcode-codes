class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &a, int target) {
        // write your code here
        vector<int> res;
        int l, r, m;
        l = 0, r = a.size()-1;
        while(l<=r){
            m = (l+r)/2;
            if(a[m]==target){
                int low = m, high = m;
                while(low>=0&&a[low]==target){
                    low--;
                }
                while(high<a.size()&&a[high]==target){
                    high++;
                }
                low++; high--;
                res.push_back(low);
                res.push_back(high);
                
                return res;
            }else if(a[m]<target){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        
        res.push_back(-1);
        res.push_back(-1);
        
        return res;
    }
};