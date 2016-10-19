class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> a, vector<int> b) {
        // write your code here
        int n = a.size();
        double aa = 0, bb = 0;
        for(int i=0; i<n; ++i)
        {
            aa += a[i]*a[i];
            bb += b[i]*b[i];
        }
        aa = sqrt(aa);
        bb = sqrt(bb);
        if(!aa||!bb)    return 2;
        double cc = 0;
        for(int i=0; i<n; ++i)  cc += a[i]*b[i];
        return cc/(aa*bb);
    }
};
