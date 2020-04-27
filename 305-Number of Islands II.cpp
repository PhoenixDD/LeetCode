class Solution {
public:
    int Find(int n)
    {
        return Parent[n]==n?n:Parent[n]=Find(Parent[n]);
    }
    void Union(int l,int r)
    {
        int lSet=Find(l),rSet=Find(r);
        if(lSet!=rSet)
        {
            numIslands--;
            Rank[lSet]<Rank[rSet]?Parent[lSet]=rSet:Parent[rSet]=lSet;
            if(Rank[lSet]==Rank[rSet])
                Rank[lSet]++;
        }
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions)
    {
        Rank.resize(m*n,0),Parent.resize(m*n,0);
        bool visited[m*n];
        memset(visited,false,sizeof visited);
        for(int i=0;i<m*n;i++)
            Parent[i]=i;
        int x,y;
        vector<int> result;
        for(vector<int> &v:positions)
        {
            if(!visited[v[0]*n+v[1]])
            {
                numIslands++;
                for(int d=0;d<4;d++)
                {
                    x=v[0]+dirs[d],y=v[1]+dirs[d+1];
                    if(x>=0&&y>=0&&x<m&&y<n&&visited[x*n+y])
                        Union(x*n+y,v[0]*n+v[1]);
                }
                visited[v[0]*n+v[1]]=true;
            }
            result.push_back(numIslands);
        }
        return result;
    }
    private:
    vector<int> Rank,Parent,dirs={-1,0,1,0,-1};
    int numIslands=0;
};