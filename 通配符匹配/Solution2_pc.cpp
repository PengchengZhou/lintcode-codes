/*
	思路：动态规划。dp[i][j]表示s[0...i-1]与p[0...j-1]是否匹配。
*/
class Solution {  
public:  
    /** 
     * @param s: A string  
     * @param p: A string includes "?" and "*" 
     * @return: A boolean 
     */  
    bool isMatch(const char *s, const char *p) {  
        // write your code here  
        int n = strlen(s);  
        int m = strlen(p);  
        vector<vector<bool> > dp(n+1,vector<bool>(m+1,false));  
        
        dp[0][0] = true;
        for(int i=0; i<m; ++i){
            if(p[i]!='*') { break; }
            dp[0][i+1] = true;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1]=='*'){
                    for(int k=i; k>=0; k--){
                        dp[i][j] = dp[i][j]||dp[k][j-1];
                    }
                }else{
                    dp[i][j] = dp[i-1][j-1]&&s[i-1]==p[j-1];
                }
            }
        }
        
        return dp[n][m];  
    }  
}; 