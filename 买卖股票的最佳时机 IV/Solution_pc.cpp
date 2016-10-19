struct Deal{
    // 买入和卖出价
    int low, high;
    Deal(int l, int h, int d):low(l), high(h){}
};

class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &p) {
        // write your code here
        int n = p.size();
        if(n==0)    return 0;

        int res = 0;

        vector<Deal> vd;

        int lowest = p[0];
        for(int i=1; i<n; ++i)
        {
            if(p[i]<p[i-1]){
                if(p[i-1]>lowest){
                    res += p[i-1]-lowest;
                    vd.push_back(Deal(lowest, p[i-1], 0x7fffffff));
                }
                lowest = p[i];
            }
        }
        if(p[n-1]>lowest){
            res += p[n-1]-lowest;
            vd.push_back(Deal(lowest, p[n-1], 0x7fffffff));
        }

        // 选择一些相邻的交易进行合并,使得总交易次数小于等于k
        while(vd.size()>k){
            vector<Deal> vd1;
            for(int i=0; i<vd.size(); ++i){
                vd1.push_back(vd[i]);
            }
            int delta = 0x7fffffff;
            int idx = -1;
            int low = 0, high = 0;
            for(int i=1; i<vd1.size(); ++i){
                int low1 = vd1[i-1].low;
                int high1 = vd1[i-1].high;
                int low2 = vd1[i].low;
                int high2 = vd1[i].high;
                
                int delta1;
                
                if(low1<=low2&&low2<=high1&&high1<=high2){
                    delta1 = high1-low2;
                    if(delta1<delta){
                        delta = delta1;
                        low = low1;
                        high = high2;
                        idx = i;
                    }
                }else if(low1<=low2&&low2<=high2&&high2<=high1){
                    delta1 = high2-low2;
                    if(delta1<delta){
                        delta = delta1;
                        low = low1;
                        high = high1;
                        idx = i;
                    }
                }else if(low2<=low1&&low1<=high1&&high1<=high2){
                    delta1 = high1-low1;
                    if(delta1<delta){
                        delta = delta1;
                        low = low2;
                        high = high2;
                        idx = i;
                    }
                }else{
                    delta1 = min(high1-low1, high2-low2);
                    if(delta1<delta){
                        delta = delta1;
                        if(high1-low1<high2-low2){
                            low = low2;
                            high = high2;
                        }else{
                            low = low1;
                            high = high1;
                        }
                        idx = i;
                    }
                }
            }
            res -= delta;
            vd1[idx-1].high = high;
            vd1[idx-1].low = low;
            vd.clear();
            for(int i=0; i<vd1.size(); ++i){
                if(i!=idx){
                    vd.push_back(vd1[i]);
                }
            }
        }

        return res;
    }
};