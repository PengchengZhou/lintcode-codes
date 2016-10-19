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
        
        vector<int> a1 = vector<int>(n, 0);
        vector<int> a2 = vector<int>(n, 0);
        
        int lowest = p[0];
        a1[0] = 0;
        for(int i=1; i<n; ++i){
            a1[i] = max(a1[i-1], p[i]-lowest);
            lowest = min(lowest, p[i]);
        }
        
        int highest = p[n-1];
        a2[n-1] = 0;
        for(int i=n-2; i>=0; --i){
            a2[i] = max(a2[i+1], highest-p[i]);
            highest = max(highest, p[i]);
        }
        
        int res = 0;
        for(int i=0; i<n; ++i){
            res = max(res, a1[i]+a2[i]);
        }
        
        return res;
    }
};