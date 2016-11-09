class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        
        // 注意考虑j=31的情况
        // 注意通过将0xffffffff移位取反再与给定数相与的方法来将高位置0的技巧
        int f1 = j==31?0:(n>>(j+1))<<(j+1), f2 = m<<i, f3 = n&(~(0xffffffff<<i));
        
        return f1|f2|f3;
    }
};