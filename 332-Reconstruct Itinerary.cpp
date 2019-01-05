class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adjacency_list;
    vector<string> result;
    void dfs(string &node)
    {
        string temp;
        while(!adjacency_list[node].empty())
        {
            temp=adjacency_list[node].top();
            adjacency_list[node].pop();
            dfs(temp);            
        }
        result.push_back(node);
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) 
    {
        adjacency_list.reserve(tickets.size());
        for(pair<string,string> &p:tickets)
            adjacency_list[p.first].push(p.second);
        string begin="JFK";
        dfs(begin);
        reverse(result.begin(),result.end());
        return result;
    }
};