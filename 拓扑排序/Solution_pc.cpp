#include <map>
#include <algorithm>

using namespace std;

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    int n; 
    vector<DirectedGraphNode*> res;
    map<unsigned long, bool> vis;
    
    void dfs(DirectedGraphNode* now)
    {
        vis[(unsigned long)now] = true;
        vector<DirectedGraphNode *> &neighbors = now->neighbors;
        int sz = neighbors.size();
        for(int i=0; i<sz; ++i)
        {
            if(!vis[(unsigned long)neighbors[i]])   dfs(neighbors[i]);
        }
        res.push_back(now);
    }
    
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        map<unsigned long, int> indegree;
        n = graph.size();
        
        for(int i=0; i<n; ++i)
        {
            vector<DirectedGraphNode *> &neighbors = graph[i]->neighbors;
            int sz = neighbors.size();
            for(int j=0; j<sz; ++j) ++indegree[(unsigned long)neighbors[j]];
        }
        
        res.clear();
        vis.clear();
        for(int i=0; i<n; ++i)
            if(indegree[(unsigned long)graph[i]]==0)    dfs(graph[i]);
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};