class Solution {
public:
    unordered_map<string,unordered_map<string,double>> adjList;
    unordered_set<string> visited;
    double getResult(string from, string to)
    {
        visited.insert(from);
        if(!adjList.count(from))
            return -1;
        if(adjList[from].count(to))
            return adjList[from][to];
        double cur_res;
        for(auto it=adjList[from].begin();it!=adjList[from].end();it++)
            if(!visited.count(it->first))
            {
                cur_res=getResult(it->first,to);
                if(cur_res!=-1)
                    return cur_res*it->second;
            }
        return -1;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) 
    {
        vector<double> result;
        double cur_res;
        for(int i=0;i<values.size();i++)
        {
            adjList[equations[i].first][equations[i].second]=values[i];
            if(values[i]!=0)
                adjList[equations[i].second][equations[i].first]=1/values[i];
            adjList[equations[i].second][equations[i].second]=1;
            adjList[equations[i].first][equations[i].first]=1;
        }
        for(pair<string,string> &q:queries)
        {
            result.push_back(getResult(q.first,q.second));
            visited.clear();
        }
        return result;
    }
};