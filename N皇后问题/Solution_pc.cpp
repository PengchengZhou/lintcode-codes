// dfs���ݹ�
// v[i] = j��ʾ��i�еĻʺ�λ�ڵ�j��
// check�������ڼ��v[i]=j�Ƿ�Ϸ���
//      ��1��ÿ��ֻ����1���ʺ�v����Ķ����Ѿ�����
//      ��2��ÿ��ֻ����1���ʺ󣺲�����0<=k<iʹ��v[k]==j
//      ��3���������������ϻʺ�λ��ͬһб���� ��������0<=k<iʹ��k-v[k]==i-j����k+v[k]==i+j

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
