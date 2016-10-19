class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if(n==1){
            return a%b;
        }
        if(n==0){
            return 1%b;
        }
        long long x = fastPower(a, b, n/2);
        long long y;
        if(n%2){
            y = (x*(a%b))%b;
            return (x*y)%b;
        }else{
            return (x*x)%b;
        }
    }
};