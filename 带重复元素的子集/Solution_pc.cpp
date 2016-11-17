// ±©ËÑ

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    void dfs(vector<int> &s, vector<int> &maxNums, int k, vector<vector<int> > &res, vector<int> tmp){
        if(k==maxNums.size()) { res.push_back(tmp); }
        else{
            for(int i=0; i<=maxNums[k]; ++i){
                vector<int> tmp1(tmp);
                for(int j=0; j<i; ++j) { tmp1.push_back(s[k]); }
                dfs(s, maxNums, k+1, res, tmp1);
            }
        }
    }
    
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        vector<int> s(S);
        sort(s.begin(), s.end());
        
        int cnt = 0;
        vector<int> maxNums;
        for(int i=0; i<s.size(); ++i){
            if(i==0||s[i]!=s[i-1]){
                maxNums.push_back(1);
                s[cnt++] = s[i];
            }
            else { maxNums[cnt-1]++; }
        }
        
        vector<vector<int> > res;
        vector<int> tmp;
        
        dfs(s, maxNums, 0, res, tmp);

        return res;
    }
};
