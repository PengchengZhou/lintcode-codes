class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        int max_len = 0, n = L.size();
        
        for(int i=0; i<n; ++i){
            max_len = max(max_len, L[i]);
        }
        
        // 二分，唯一需要注意的是数据范围，如果不用long long的话会越界
        long long low = 1, high = max_len;
        int res = 0;
        while(low<=high){
            int mid = (low+high)>>1;
            long long s = 0;
            for(int i=0; i<n; ++i){
                s += L[i]/mid;
            }
            if(s>=k){
                res = max(res, mid);
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        return res;
    }
};