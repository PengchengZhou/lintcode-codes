class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        
        int res = 0;
        
        if(strs.size()>0){
            res = strs[0].length();
        }
        
        for(int i=1; i<strs.size(); ++i){
            int tmp = 0;
            for(int j=0; j<res; ++j){
                if(strs[i][j]==strs[i-1][j]){
                    tmp++;
                }else{
                    break;
                }
            }
            res = min(res, tmp);
        }
        
        return strs.size()==0?"":strs[0].substr(0, res);
    }
};