class Solution {
public:
    unordered_map<int,unordered_map<int,bool>> memo;
    bool canCross(vector<int>& stones,int pos,int k)
    {
        if(pos==stones.size()-1)
            return memo[pos][k]=true;
        if(memo[pos].count(k))
            return memo[pos][k];
        int gap;
        for(int i=pos+1;i<stones.size();i++)
        {
            gap=stones[i]-stones[pos];
            if(gap>k+1)
                return memo[pos][k]=false;
            if(gap>=k-1&&canCross(stones,i,gap))
                return memo[pos][k]=true;
        }
        return memo[pos][k]=false;
    }
    bool canCross(vector<int>& stones) 
    {
        memo.reserve(stones.size());
        return canCross(stones,0,0);
    }
};