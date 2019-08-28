//Kruskal's MST, treat house 0(imaginary) which is the first well, and pipes 0 to each house is the well dig cost
class Solution {
public:
    vector<int> parent,Rank;
    int Find(int x)
    {
        return parent[x]==x?x:parent[x]=Find(parent[x]);
    }
    void Union(int x,int y)
    {
        int xset=Find(x),yset=Find(y);
        if(xset!=yset)
        {
            Rank[xset]<Rank[yset]?parent[xset]=yset:parent[yset]=xset;
            if(Rank[xset]==Rank[yset])
                Rank[xset]++;
        }
    }
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) 
    {
        Rank.resize(n+1,0),parent.resize(n+1);
        for(int i=0;i<parent.size();i++)
            parent[i]=i;
        for(int i=0;i<wells.size();i++)
            pipes.push_back({0,i+1,wells[i]});
        sort(pipes.begin(),pipes.end(),[](vector<int>&l,vector<int>&r){return l[2]<r[2];});
        int result=0;
        for(vector<int>&v:pipes)
            if(Find(v[0])!=Find(v[1]))
            {
                result+=v[2];
                Union(v[0],v[1]);
            }
        return result;
    }
};