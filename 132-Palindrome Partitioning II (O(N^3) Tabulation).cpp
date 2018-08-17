class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<bool>> pal_memo;
    int minCut(string s) 
    {
        if(s.empty())
            return 0;
        vector<vector<int>> memo(s.length(),vector<int>(s.length(),INT_MAX));
        vector<vector<bool>> pal_memo(s.length(),vector<bool>(s.length(),0));
        for(int l=1;l<=s.length();l++)
            for(int i=0;i<=s.length()-l;i++)
            {
                if(l==1)
                    pal_memo[i][i]=true;
                else if(l==2)
                    pal_memo[i][i+1]=s[i]==s[i+1];
                else
                    pal_memo[i][i+l-1]=s[i]==s[i+l-1]&&pal_memo[i+1][i+l-2];
                if(pal_memo[i][i+l-1])
                    memo[i][i+l-1]=0;
                else
                    for(int k=i;k<i+l-1;k++)
                        memo[i][i+l-1]=min(memo[i][i+l-1],1+memo[i][k]+memo[k+1][i+l-1]);
            }
        return memo[0][s.length()-1];
    }
};