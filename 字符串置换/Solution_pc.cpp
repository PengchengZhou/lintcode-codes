#include <map>

class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& sa, string& sb) {
        // Write your code here
        if(sa.size()!=sb.size()){
            return false;
        }
        map<char, int> cnt;
        for(int i=0; i<sa.size(); ++i){
            cnt[sa[i]]++;
        }
        for(int i=0; i<sb.size(); ++i){
            cnt[sb[i]]--;
        }
        for(map<char, int>::iterator it=cnt.begin(); it!=cnt.end(); it++){
            if(it->second!=0){
                return false;
            }
        }
        return true;
    }
};