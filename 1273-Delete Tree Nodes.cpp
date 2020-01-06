class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) 
    {
        vector<int> result(nodes,0);
        for(int i=nodes-1;i>0;i--)
            value[parent[i]]+=value[i],result[parent[i]]+=value[i]?result[i]+1:0;
        return value.front()?result.front()+1:0;
    }
};