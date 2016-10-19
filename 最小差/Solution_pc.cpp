struct Data{
    int value;
    int arr;
    Data():value(0), arr(0){}
    Data(int _value, int _arr):value(_value),arr(_arr){}
    bool operator<(const Data& data)const{
        return value<data.value;
    }
};

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &a, vector<int> &b) {
        // write your code here
        int na = a.size(), nb = b.size();
        int n = na+nb;
        Data v[n];
        int i = 0;
        while(i<na){
            v[i].value = a[i];
            v[i++].arr = 1;
        }
        while(i<n){
            v[i].value = b[i-na];
            v[i++].arr = 2;
        }
        sort(v, v+n);
        
        int ans = 0x7fffffff;
        
        for(i=1; i<n; ++i){
            if(v[i].arr!=v[i-1].arr){
                ans = min(ans, abs(v[i].value-v[i-1].value));
            }
        }
        
        return ans;
    }
};