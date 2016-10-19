class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    /* 
    // ��1���Ƚ������ӽ�800�����
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        int n = strs.size();
        vector<vector<int> > cnt = vector<vector<int> >(n, vector<int>(26, 0));
        for(int i=0; i<n; ++i){
            for(int j=0; j<strs[i].size(); ++j){
                cnt[i][strs[i][j]-'a']++;
            }
        }
        
        vector<string> res;
        vector<bool> flag = vector<bool>(n, false);
        
        for(int i=0; i<n-1; ++i){
            if(flag[i]) continue;
            for(int j=i+1; j<n; ++j){
                if(flag[j]) continue;
                bool tmp = true;
                for(int k=0; k<26; ++k){
                    if(cnt[i][k]!=cnt[j][k]){
                        tmp = false;
                        break;
                    }
                }
                if(tmp){
                    if(!flag[i]){
                        res.push_back(strs[i]);
                        flag[i] = true;
                    }
                    if(!flag[j]){
                        res.push_back(strs[j]);
                        flag[j] = true;
                    }
                }
            }
        }
        
        return res;
    }
    */
    
    /*
    // ��2, ͦ��ģ���ʮ����
    vector<string> anagrams(vector<string> &strs) {
        vector<string>  strs1 = strs;
        int n = strs.size();
        for(int i=0; i<n; ++i){
            sort(strs1[i].begin(), strs1[i].end());
        }
        map<string, int> mp;
        vector<bool> flag = vector<bool>(n, false);
        vector<string>  res;
        for(int i=0; i<n; ++i){
            if(mp.find(strs1[i])==mp.end()){
                mp[strs1[i]] = i;
            }else{
                int j = mp[strs1[i]];
                if(!flag[j]){
                    res.push_back(strs[j]);
                    flag[j] = true;
                }
                if(!flag[i]){
                    res.push_back(strs[i]);
                    flag[i] = true;
                }
                mp[strs1[i]] = i;
            }
        }
        
        return res;
    }
    */
    
    
    // ��3, ��hashֵ�����, �ȷ�2��һ���
    vector<string> anagrams(vector<string> &strs) {
        int n = strs.size();
        vector<bool> flag = vector<bool>(n, false);
        
        unsigned long long p[26];
        p[0] = 1;
        for(int i=1; i<26; ++i){
            p[i] = p[i-1]*26;
        }
        
        map<unsigned long long, int> mp;
        vector<string> res;
        
        for(int i=0; i<n; ++i){
            unsigned long long x = 0;
            for(int k=0; k<strs[i].size(); ++k){
                x += p[strs[i][k]-'a'];
            }
            if(mp.find(x)==mp.end()){
                mp[x] = i;
            }else{
                int j = mp[x];
                if(!flag[j]){
                    res.push_back(strs[j]);
                    flag[j] = true;
                }
                if(!flag[i]){
                    res.push_back(strs[i]);
                    flag[i] = true;
                }
                mp[x] = i;
            }
        }
        
        return res;
    }
    
};
