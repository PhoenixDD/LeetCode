class Solution {
public:
    vector<int> balances;
    int dfs(int index)
    {
        if(index==balances.size())
            return 0;
        if(balances[index]==0)
            return dfs(index+1);
        int result=INT_MAX;
        for(int i=index+1,prev=0;i<balances.size();i++)
            if(prev!=balances[i]&&balances[index]*balances[i]<0)
                prev=balances[i],balances[i]+=balances[index],result=min(result,1+dfs(index+1)),balances[i]-=balances[index];
        return result==INT_MAX?0:result;
    }
    int minTransfers(vector<vector<int>>& transactions) 
    {
        unordered_map<int,int> t;
        for(vector<int> &v:transactions)
            t[v[0]]-=v[2],t[v[1]]+=v[2];
        for(auto &p:t)
            if(p.second)
                balances.push_back(p.second);
        sort(balances.begin(),balances.end());
        int i=0,j=balances.size()-1;
        return dfs(0);
    }
};