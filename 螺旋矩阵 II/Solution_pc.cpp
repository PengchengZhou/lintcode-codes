class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        vector<vector<int> > res;
        for(int i=0; i<n; ++i){
            vector<int> tmpV(n);
            res.push_back(tmpV);
        }
        int all = n*n;
        
        int right = n-1, down = n-1, left = 0, up = 1;
        
        int col = 0, row = 0;
        int direction = 1;
        
        for(int i=1; i<=all; ++i){
            res[col][row] = i;
            
            switch(direction){
                case 1: // right
                    if(row<right){
                        row++;
                    }else{
                        col++;
                        direction = 2;
                        right--;
                    }
                    break;
                case 2: // down
                    if(col<down){
                        col++;
                    }else{
                        row--;
                        direction = 3;
                        down--;
                    }
                    break;
                case 3: // left
                    if(row>left){
                        row--;
                    }else{
                        col--;
                        direction = 4;
                        left++;
                    }
                    break;
                case 4: // up
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
        
        return res;
    }
};