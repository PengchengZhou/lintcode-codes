// 直接广搜即可

struct Node{
    string s;
    int len;
    Node(string _s, int _len):s(_s), len(_len){}
};

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        queue<Node> q;
        unordered_set<string> visited;

        q.push(Node(start, 1));
        visited.insert(start);
        while(!q.empty()){
            Node &now = q.front();

            if(now.s==end) { return now.len; }

            string &s = now.s;
            for(int i=0; i<s.length(); ++i){
                for(int j=0; j<26; ++j){
                    if(s[i]!=j+'a'){
                        string s1 = s;
                        s1[i] = j+'a';
                        if(s1==end || dict.find(s1)!=dict.end()&&visited.find(s1)==visited.end()){
                            q.push(Node(s1, now.len+1));
                            visited.insert(s1);
                        }
                    }
                }
            }

            q.pop();
        }

        return 0;
    }
};