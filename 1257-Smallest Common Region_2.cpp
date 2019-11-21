class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) 
    {
        unordered_map<string,string> parent;
        for(vector<string> &v:regions)
            for(int i=1;i<v.size();i++)
                parent[v[i]]=v.front();
        string r1=region1,r2=region2;
        while(r1!=r2)
            r1=r1==""?region2:parent[r1],r2=r2==""?region1:parent[r2];
        return r1;
    }
};