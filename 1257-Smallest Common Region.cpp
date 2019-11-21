class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) 
    {
        unordered_map<string,string> parent;
        unordered_set<string> encounteredParents;
        for(vector<string> &v:regions)
            for(int i=1;i<v.size();i++)
                parent[v[i]]=v.front();
        while(""!=region1)
            encounteredParents.insert(region1),region1=parent[region1];
        while(""!=region2)
            if(encounteredParents.count(region2))
                return region2;
            else
                region2=parent[region2];
        return "";
    }
};