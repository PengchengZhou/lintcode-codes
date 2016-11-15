class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    
	// ¼ÇÒä»¯ËÑË÷
    /*
    bool dp(vector<int> &A, vector<int> &f, int i){
        if(i>=A.size()-1){
            return true;
        }
        
        if(f[i]!=-1){
            return f[i];
        }
        
        f[i] = 0;
        for(int j=0; j<=A[i]; ++j){
            if(dp(A, f, i+j)){
                f[i] = 1;
            }
        }
        
        return f[i];
    }
    
    bool canJump(vector<int> A) {
        // write you code here
        vector<int> f(A.size(), -1);
        
        return dp(A, f, 0);
    }
    */
    
	// Ì°ÐÄ
    int findPrev(vector<int> &A, int i){
        for(int j=i-1; j>=0; --j){
            if(j+A[j]>=i){
                return j;
            }
        }
        
        return -1;
    }
    
    bool canJump(vector<int> A) {
        // write you code here
        int i = A.size()-1;
        
        while(i>0){
            i = findPrev(A, i);
        }
        
        return i==0;
    }
};
