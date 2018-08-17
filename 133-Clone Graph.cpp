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
    unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> map;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if(!node)
            return NULL;
        if(map.count(node))
            return map[node];
        UndirectedGraphNode *clone=new UndirectedGraphNode(node->label);
        map[node]=clone;
        for(auto &i:node->neighbors)
                clone->neighbors.push_back(cloneGraph(i));
        return clone;
    }
};