class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        
        // ע�⿼��j=31�����
        // ע��ͨ����0xffffffff��λȡ���������������ķ���������λ��0�ļ���
        int f1 = j==31?0:(n>>(j+1))<<(j+1), f2 = m<<i, f3 = n&(~(0xffffffff<<i));
        
        return f1|f2|f3;
    }
};