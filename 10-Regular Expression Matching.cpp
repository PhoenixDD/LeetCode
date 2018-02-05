class Solution {
public:
    vector<vector<int>> memo;
    bool match(string &s,string &p,int i,int j)
    {
        if(i>=0&&j>=0&&memo[i][j]!=-1)
            return memo[i][j];
        else if(i==0&&j==0)
            return true;
        else if(i<0||j<=0)
            return false;
        else if(s[i-1]==p[j-1]||p[j-1]=='.')
            return memo[i][j]=match(s,p,i-1,j-1);
        else if(p[j-1]=='*')
                return memo[i][j]=match(s,p,i,j-1)||match(s,p,i,j-2)||(s[i-1]==p[j-2]||p[j-2]=='.')&&match(s,p,i-1,j);
        return memo[i][j]=false;

    }
    bool isMatch(string s, string p)
    {
        memo.resize(s.length()+1,vector<int>(p.length()+1,-1));
        return match(s,p,s.length(),p.length());
    }
};
