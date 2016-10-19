#include <algorithm>

using namespace std;

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
            res = max(res, p[i]-lowest);
            lowest = min(lowest, p[i]);
        }
        
        return res;
    }
};
