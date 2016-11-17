// ������˼·��BFS
// ������ҪһЩ�Ż����ܲ���ʱ��������
//   ��1����֦��ͬһ���㲻�������Σ�����·��������ȣ��������
//        �����ڴӲ�ͬ·�����ﵱǰ�㣬��Ϊ��ĿҪ������������
//        ·����������������Ҫ���ǣ���
//   ��2���Ż�BFS�Ķ��г��ȣ���ΪҪ����������·������Щ���
//        ·��֮����ܻ��н��棬����������Ż���ͬһ�������
//        ��Ӷ�Σ����¶��г��ȵ����ӣ��Ӷ�����ʱ�俪������ˣ�
//        ����ͨ����¼ÿ����ĸ��׽�㼯�ϣ�ʹ��ÿ����������
//        һ�Σ��Ӷ���С���г��ȡ�

struct Node{
    string s;
    int len;
}nodes[3333333];
int cnt = 0;

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    void dfs(unordered_map<string, unordered_set<string> > &parents, string start, string end, vector<vector<string> > &res, vector<string> &path){
        path.push_back(end);

        if(start!=end){
            for(unordered_set<string>::iterator it = parents[end].begin(); it!=parents[end].end(); it++){
                dfs(parents, start, *it, res, path);
                path.erase(path.begin()+path.size()-1);
            }
        }else{
            vector<string> v;
            for(int i=path.size()-1; i>=0; --i) { v.push_back(path[i]); }
            res.push_back(v);
        }
    }
    void generatePaths(unordered_map<string, unordered_set<string> > &parents, string start, string end, vector<vector<string> > &res){
        vector<string> path;
        dfs(parents, start, end, res, path);
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        vector<vector<string> > res;

        queue<Node *> q;
        unordered_map<string, Node *> visited;
        unordered_map<string, unordered_set<string> > parents;

        Node *nodeStart = &nodes[cnt++];
        nodeStart->s = start;
        nodeStart->len  = 1;
        q.push(nodeStart);
        visited[start] = nodeStart;

        dict.insert(end);
        dict.erase(start);

        while(dict.size()>0&&!q.empty()){
            Node *now = q.front();
            string &s = now->s;

            if(s==end){
                generatePaths(parents, start, end, res);

                return res;
            }

            for(int i=0; i<s.length(); ++i){
                for(int j=0; j<26; ++j){
                    if(s[i]!=j+'a'){
                        string s1 = s;
                        s1[i] = j+'a';

                        if(dict.find(s1)!=dict.end()&&(visited.find(s1)==visited.end()||now->len+1==visited[s1]->len)){
                            if(visited.find(s1)==visited.end()||now->len+1<=visited[s1]->len){
                                if(visited.find(s1)==visited.end()){
                                    Node *node = &nodes[cnt++];
                                    node->s = s1;
                                    node->len = now->len+1;
                                    visited[s1] = node;
                                    q.push(node);
                                }

                                if(parents.find(s1)==parents.end()) { parents[s1] = unordered_set<string>(); }
                                parents[s1].insert(now->s);
                            }
                            else { dict.erase(s1); }
                        }
                    }
                }
            }

            if(!q.empty()) { q.pop(); }
        }

        return res;
    }
};