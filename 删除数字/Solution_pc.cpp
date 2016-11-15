// ȥ��kλ <==> ѡ��n-kλ
// ̰�ĵ���λѡȡ����

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        int n = A.length(), m = n-k;
        string res = "";
        
        int start = 0, end = n-m;
        for(int i=1; i<=m; ++i){
            char tmp = ':'; // ':'��ASCII�����ñ�'9'��ASCII���
            int pos = -1;
            for(int j=start; j<=end; ++j){
                if(A[j]<tmp){
                    tmp = A[j];
                    pos = j;
                }
            }
            res.push_back(tmp);
            start = pos+1;
            end = n-m+i;
        }
        
		// ȥ��ǰ��0
        int j = 0;
        for(int i=0; i<res.size()-1; ++i){
            if(res[i]=='0'){
                j++;
            }else{
                break;
            }
        }
        
        return res.substr(j);
    }
};
