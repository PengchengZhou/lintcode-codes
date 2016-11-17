// 基本的思路是BFS
// 但是需要一些优化才能不超时，包括：
//   （1）剪枝：同一个点不经过两次（除非路径长度相等，这种情况
//        是由于从不同路径到达当前点，因为题目要求给出所有最短
//        路径，因此这种情况需要考虑）；
//   （2）优化BFS的队列长度：因为要求出所有最短路径，这些最短
//        路径之间可能会有交叉，如果不加以优化，同一个点可能
//        入队多次，导致队列长度的增加，从而增加时间开销，因此，
//        我们通过记录每个点的父亲结点集合，使得每个点最多入队
//        一次，从而减小队列长度。

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