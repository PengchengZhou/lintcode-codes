#include <vector>

using std::vector;

class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // Write your code here
        if(n<=0)    return 1;
        if(n==1)    return k;
        
        /*vector<vector<int> > dp(n, vector<int>(2));
        
        dp[1][0] = k;
        dp[1][1] = k*(k-1);
        
        for(int i=2; i<n; ++i)
        {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = (dp[i-1][0]+dp[i-1][1])*(k-1);
        }
        
        return dp[n-1][0]+dp[n-1][1];*/
        
        int d1 = k, d2 = k*(k-1);
        
        for(int i=2; i<n; ++i)
        {
            int tmp = d1;
            d1 = d2;
            d2 = (tmp+d2)*(k-1);
        }
        
        return d1+d2;
    }
};