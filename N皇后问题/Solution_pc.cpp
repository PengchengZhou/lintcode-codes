// dfs，递归
// v[i] = j表示第i行的皇后位于第j列
// check函数用于检查v[i]=j是否合法：
//      （1）每行只能有1个皇后：v数组的定义已经满足
//      （2）每列只能有1个皇后：不存在0<=k<i使得v[k]==j
//      （3）不能有两个以上皇后位于同一斜线上 ：不存在0<=k<i使得k-v[k]==i-j或者k+v[k]==i+j

class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    bool check(vector<int> &v, int i, int j){
        int tmp1 = i-j, tmp2 = i+j;
        for(int k=0; k<i; ++k){
            if(v[k]==j || tmp1==k-v[k] || tmp2==k+v[k]) { return false; }
        }
        
        return true;
    }
    
    void dfs(vector<int> &v, int cnt, vector<vector<string> > &res){
        if(cnt==v.size()){
            vector<string> tmp;
            for(int i=0; i<cnt; ++i){
                string s(cnt, '.');
                s[v[i]] = 'Q';
                tmp.push_back(s);
            }
            res.push_back(tmp);
            return;
        }
        
        int i = cnt;
        for(int j=0; j<v.size(); ++j){
            if(check(v, i, j)){
                v[i] = j;
                dfs(v, cnt+1, res);
            }
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<int> v(n, 0);
        vector<vector<string> > res;
        
        dfs(v, 0, res);
        
        return res;
    }
};
