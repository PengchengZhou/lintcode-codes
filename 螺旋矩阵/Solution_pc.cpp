class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        vector<int> res;
        
        int m = matrix.size();
        if(m!=0){
            int n = matrix[0].size();
            
            int all = m*n;
            
            int col = 0, row = 0;
            
            int right = n-1;
            int down = m-1;
            int left = 0;
            int up = 1;
            
            int direction = 1;
            
            for(int i=0; i<all; ++i){
                res.push_back(matrix[col][row]);
                
                switch(direction){
                    case 1: //right
                        if(row<right){
                            row++;
                        }else{
                            col++;
                            direction = 2;
                            right--;
                        }
                        break;
                    case 2: //down
                        if(col<down){
                            col++;
                        }else{
                            row--;
                            direction = 3;
                            down--;
                        }
                        break;
                    case 3: //left
                        if(row>left){
                            row--;
                        }else{
                            col--;
                            direction = 4;
                            left++;
                        }
                        break;
                    case 4: //up
                        if(col>up){
                            col--;
                        }else{
                            row++;
                            direction = 1;
                            up++;
                        }
                        break;
                }
            }
        }
        
        return res;
    }
};