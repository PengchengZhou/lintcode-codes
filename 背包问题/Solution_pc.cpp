class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    /*
    // 超内存
    int backPack(int m, vector<int> a) {
        // write your code here
        int n = a.size();
        if(!n)  return 0;
        
        vector<vector<int> > dp = vector<vector<int> >(n, vector<int>(m+1, 0));
        if(a[0]<=m) dp[0][a[0]] = a[0];
        for(int i=1; i<n; ++i){
            for(int j=0; j<=m; ++j){
                if(j>=a[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]]+a[i]);
                else    dp[i][j] = dp[i-1][j];
            }
        }
        
        int res = 0;
        for(int i=0; i<=m; ++i){
            res = max(res, dp[n-1][i]);
        }
        
        return res;
    }
    */
    // 优化空间复杂度
    int backPack(int m, vector<int> a) {
        // write your code here
        int n = a.size();
        if(!n)  return 0;
        
        vector<int> dp = vector<int>(m+1, 0);
        if(a[0]<=m) dp[a[0]] = a[0];
        for(int i=1; i<n; ++i){
            for(int j=m; j>=a[i]; --j){
                dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
            }
        }
        
        int res = 0;
        for(int i=0; i<=m; ++i){
            res = max(res, dp[i]);
        }
        
        return res;
    }
};