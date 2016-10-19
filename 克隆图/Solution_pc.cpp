/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        UndirectedGraphNode *ret = NULL;
        
        if(node!=NULL){
            ret = new UndirectedGraphNode(node->label);
            
            map<int, UndirectedGraphNode *> addr;
            addr[ret->label] = ret;
            
            map<unsigned long, bool> vis;
            queue<UndirectedGraphNode *> q1;
            queue<UndirectedGraphNode *> q2;
            q1.push(node);
            vis[(unsigned long)node] = true;
            q2.push(ret);
            while(!q1.empty()){
                UndirectedGraphNode *p1 = q1.front();
                q1.pop();
                UndirectedGraphNode *p2 = q2.front();
                q2.pop();
                
                vector<UndirectedGraphNode *> &neighbors = p1->neighbors;
                for(size_t i=0; i<neighbors.size(); ++i){
                    UndirectedGraphNode *tmp = NULL;
                    if(addr.find(neighbors[i]->label)==addr.end()){
                        tmp = new UndirectedGraphNode(neighbors[i]->label);
                        addr[tmp->label] = tmp;
                    }else{
                        tmp = addr[neighbors[i]->label];
                    }
                    p2->neighbors.push_back(tmp);
                    if(vis.find((unsigned long)neighbors[i])==vis.end()){
                        q1.push(neighbors[i]);
                        q2.push(p2->neighbors[i]);
                        vis[(unsigned long)neighbors[i]] = true;
                    }
                }
            }
        }
        
        return ret;
    }
};