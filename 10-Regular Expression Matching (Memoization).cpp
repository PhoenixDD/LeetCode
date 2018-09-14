class Solution {
public:
    vector<vector<int>> memo;
    bool isMatch(string s, string p,int i,int j)
    {
        if(i==0&&j==0)
            return true;
        if(i<0||j==0)
            return false;
        if(memo[i][j]!=-1)
            return memo[i][j];
        if(p[j-1]=='.'||s[i-1]==p[j-1])
            return memo[i][j]=isMatch(s,p,i-1,j-1);
        if(p[j-1]=='*')
            return memo[i][j]=(s[i-1]==p[j-2]||p[j-2]=='.')&&isMatch(s,p,i-1,j)||isMatch(s,p,i,j-2);
        return memo[i][j]=false;            
    }
    bool isMatch(string s, string p) 
    {
        memo.resize(s.length()+1,vector<int>(p.length()+1,-1));
        return isMatch(s,p,s.length(),p.length());
    }
};