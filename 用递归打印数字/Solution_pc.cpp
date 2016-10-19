class Solution {
private:
    int m, n, largest;
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    
    void recursion(vector<int> &results, int start){
        if(m<=n){
            largest *= 10;
            for(int i=start; i<largest; ++i){
                results.push_back(i);
            }
            m++;
            recursion(results, largest);
        }
    }
    
    vector<int> numbersByRecursion(int n) {
        // write your code here
        this->m = 1;
        this->n = n;
        this->largest = 1;
        
        vector<int> results;
        
        recursion(results, 1);
        
        return results;
    }
};