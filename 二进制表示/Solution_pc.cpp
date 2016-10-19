#include <cstdlib>

#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        string ret;
        
        int p = -1;
        int len = n.length();
        
        // 找到小数点的位置
        for(int i=0; i<len; ++i)
        {
            if(n[i]=='.')
            {
                p = i;
                break;
            }
        }
        
        char* pEnd;
        
        // 当p==-1，说明n是整数，没有小数部分
        if(p==-1)
        {
            long long x = strtoll(n.c_str(), &pEnd, 10);
            if(x==0)    return "0";
            while(x)
            {
                ret.push_back(x&1?'1':'0');
                x >>= 1;
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }
        
        // 有小数部分的情况
        string str_ipart, str_dpart;
        str_ipart = n.substr(0, p);
        str_dpart = n.substr(p+1, len-p-1);
        
        long long x_ipart, x_dpart;
        x_ipart = strtoll(str_ipart.c_str(), &pEnd, 10);
        x_dpart = strtoll(str_dpart.c_str(), &pEnd, 10);
        
        if(x_ipart==0)  ret.push_back('0');
        else
        {
            while(x_ipart)
            {
                ret.push_back(x_ipart&1?'1':'0');
                x_ipart >>= 1;
            }
            reverse(ret.begin(), ret.end());
        }
        ret.push_back('.');
        
        long long mod = 1;
        int l_dpart = len-p-1;
        while(l_dpart--)    mod *= 10;
        
        int cnt = 0;
        while(x_dpart)
        {
            if(cnt>=32)
            {
                ret = "ERROR";
                break;
            }
            x_dpart <<= 1;
            if(x_dpart>=mod)
            {
                ret.push_back('1');
                x_dpart -= mod;
            }
            else    ret.push_back('0');
            ++cnt;
        }
        if(cnt==0)  ret.pop_back();
        
        return ret;
    }
};
