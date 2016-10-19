class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &a) {
        // write your code here
        int n = a.size();
        
        for(int i=1; i<n; ++i){
            if(a[i]<a[i-1]){
                return a[i];
            }
        }
        
        return a[0];
    }
};