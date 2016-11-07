class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int len_A = A.length(), len_B = B.length();
        
        int res = 0;
        // O(n^3)Ëã·¨
        for(int i=0; i<len_A; ++i){
            for(int j=0; j<len_B; ++j){
                int tmp = 0;
                while(i+tmp<len_A&&j+tmp<len_B&&A[i+tmp]==B[j+tmp]){
                    tmp++;
                }
                res = max(res, tmp);
            }
        }
        
        return res;
    }
};
