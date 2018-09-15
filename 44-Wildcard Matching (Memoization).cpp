class Solution {
public:
    vector<vector<int>>memo;
    bool matches(string &s,string &p,int i,int j)
    {
        if(i==0&&j==0)
            return true;
        else if(i<0||j<0)
            return false;
        else if(memo[i][j]!=-1)
            return memo[i][j];
        else if(p[j-1]=='*')
            return memo[i][j]=matches(s,p,i-1,j)||matches(s,p,i,j-1);
        else if(p[j-1]=='?'||p[j-1]==s[i-1])
            return memo[i][j]=matches(s,p,i-1,j-1);
        return memo[i][j]=false;    
    }
    bool isMatch(string s, string p)
    {
        memo.resize(s.length()+1,vector<int>(p.length()+1,-1));
        return matches(s,p,s.size(),p.size());
    }
};