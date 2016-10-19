class Solution {
private:
    int m, n;
    
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int columnBinarySearch(vector<vector<int> > &matrix, int col, int target){
        int l = 0, r = m-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(matrix[mid][col]==target){
                return 1;
            }else if(matrix[mid][col]>target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        
        return 0;
    }
    
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int ret = 0;
        
        m = matrix.size();
        if(m){
            n = matrix[0].size();
            for(int i=0; i<n; ++i){
                if(matrix[0][i]<=target){
                    ret += columnBinarySearch(matrix, i, target);
                }else{
                    break;
                }
            }
        }
        
        return ret;
    }
};
