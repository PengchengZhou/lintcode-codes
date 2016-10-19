class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int cnt = 0;
        int x = 1, t = 0;
        while(t!=n){
            int d = (n/x)%10;
            x *= 10;
            if(k<d){
                cnt += (n/x+1-(k==0))*(x/10-(k==0&&x!=10));
            }else if(k==d){
                cnt += (n/x-(k==0))*(x/10-(k==0&&x!=10))+(t+1-(k==0&&x!=10));
            }else{
                cnt += (n/x-(k==0))*(x/10-(k==0&&x!=10));
            }
            t = n%x;
        }
        return cnt+(k==0);
    }
};