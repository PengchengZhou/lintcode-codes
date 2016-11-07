class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        sort(A.begin(), A.end());
        
        if(A.size()==0||A[0]>1){
            return 1;
        }
        
        for(int i=0; i<A.size()-1; ++i){
            if(A[i]>=0&&A[i+1]!=A[i]&&A[i+1]!=A[i]+1){
                return A[i]+1;
            }
            if(A[i]<0&&A[i+1]>1){
                return 1;
            }
        }
        
        int x = A[A.size()-1];
        
        return x>=0?x+1:1;
    }
};