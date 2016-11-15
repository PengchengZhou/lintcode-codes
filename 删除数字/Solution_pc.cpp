// 去掉k位 <==> 选出n-k位
// 贪心的逐位选取即可

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
            char tmp = ':'; // ':'的ASCII码正好比'9'的ASCII码大
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
        
		// 去掉前导0
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
