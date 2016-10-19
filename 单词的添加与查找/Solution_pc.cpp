#define MAX_CH 26
#define MAX_NODE 100005

int nodecnt = 0;

struct TrieNode{
    bool flag;
    TrieNode *p[MAX_CH];

    void init(){
        flag = false;
        for(int i=0; i<MAX_CH; ++i) p[i] = NULL;
    }

    void addWord(string &s, int i){
        int idx = s[i]-'a';
        if(p[idx]==NULL){
            extern TrieNode trieNode[MAX_NODE];
            p[idx] = &trieNode[nodecnt++];
            p[idx]->init();
        }
        if(i==s.size()-1)  p[idx]->flag = true;
        else    p[idx]->addWord(s, i+1);
    }

    bool search(string &s, int i){
        if(s[i]=='.'){
            bool ret = false;
            for(int j=0; j<MAX_CH; ++j){
                if(p[j]){
                        if(i==s.size()-1)  ret |= p[j]->flag;
                        else    ret |= p[j]->search(s, i+1);
						if(ret)	return true;
                }
            }
            return ret;
        }
        else{
            int idx = s[i]-'a';
            if(p[idx]){
                if(i==s.size()-1)  return p[idx]->flag;
                return p[idx]->search(s, i+1);
            }
            return false;
        }
    }
}trieNode[MAX_NODE];

struct Trie{
    TrieNode *root;

    Trie(){
        root = &trieNode[nodecnt++];
        root->init();
    }

    void addWord(string &s){
        root->addWord(s, 0);
    }

    bool search(string &s){
        return root->search(s, 0);
    }
}trie;

class WordDictionary {
public:
    void addWord(string word) {
        trie.addWord(word);
    }

    bool search(string word) {
        return trie.search(word);
    }
};