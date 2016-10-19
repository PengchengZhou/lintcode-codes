class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &p) {
        // write your code here
        int n = p.size();
        if(n==0)    return 0;
        int res = 0;
        int lowest = p[0];
        for(int i=1; i<n; ++i)
        {
            if(p[i]<p[i-1]){
                res += p[i-1]-lowest;
                lowest = p[i];
            }
        }
        if(p[n-1]>lowest)   res += p[n-1]-lowest;
        
        return res;
    }
};