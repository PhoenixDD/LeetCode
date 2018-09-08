class Solution {
public:
    vector<vector<int>> memo;
    unordered_map<char,vector<int>> map;
    int findRotateSteps(string &ring, string &key,int r,int k)
    {
        if(k==key.length())
            return 0;
        if(memo[k][r]!=-1)
            return memo[k][r];
        int Min=INT_MAX;
        for(int i:map[key[k]])
            Min=min(Min,findRotateSteps(ring,key,i,k+1)+min(abs(r-i),(int)ring.size()-abs(r-i)));
        return memo[k][r]=Min;
    }
    int findRotateSteps(string ring, string key) 
    {
        memo.resize(key.length(),vector<int>(ring.length(),-1));
        for(int i=0;i<ring.length();i++)
            map[ring[i]].push_back(i);
        return findRotateSteps(ring,key,0,0)+key.length();
    }
};