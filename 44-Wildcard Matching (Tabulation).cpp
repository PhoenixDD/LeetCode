class Solution {
public:
    bool isMatch(string s, string p) 
    {
        vector<vector<bool>> memo(s.length()+1,vector<bool>(p.length()+1,false));
        memo[0][0]=true;
        int x=0;
        if(p[0]=='*')
            for(int i=0;i<=s.length();i++)
            {
                while(p[x]=='*')
                    memo[i][++x]=true;
                x=0;
            }
        for(int i=1;i<=s.length();i++)
        {
            for(int j=1;j<=p.length();j++)
            {
                if(p[j-1]=='*')
                    memo[i][j]=memo[i-1][j]||memo[i][j-1];
                else if(p[j-1]=='?')
                    memo[i][j]=memo[i-1][j-1];
                else
                    memo[i][j]=(s[i-1]==p[j-1])&&memo[i-1][j-1];
            }
        }
        return memo[s.length()][p.length()];
    }
};