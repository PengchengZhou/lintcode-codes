#include <vector>
#include <set>

using namespace std;

class Solution {
private:
    vector<int> v;
    set<long long> s;

public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    Solution(){
        s.insert(1);
    }

    int nthUglyNumber(int n) {
        while(v.size()<n){
            long long tmp = *s.begin();
            s.erase(s.begin());
            v.push_back(tmp);
            s.insert(tmp*2);
            s.insert(tmp*3);
            s.insert(tmp*5);
        }

        return v[n-1];
    }
};