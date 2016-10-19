class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> a, vector<int> v) {
        // write your code here
        int n = a.size();
        if(!n)  return 0;
        
        vector<int> dp = vector<int>(m+1, 0);
        if(a[0]<=m) dp[a[0]] = v[0];
        for(int i=1; i<n; ++i){
            for(int j=m; j>=a[i]; --j){
                dp[j] = max(dp[j], dp[j-a[i]]+v[i]);
            }
        }
        
        int res = 0;
        for(int i=0; i<=m; ++i){
            res = max(res, dp[i]);
        }
        
        return res;
    }
};