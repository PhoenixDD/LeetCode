class Solution {
public:
    vector<vector<int>> pal_memo;
    vector<vector<int>> memo;
    bool is_pal(string &s,int i,int j)
    {
        if(memo[i][j]!=-1)
            return pal_memo[i][j];
        if(i==j)
            return pal_memo[i][j]=true;
        if(i==j-1&&s[i]==s[j])
            return pal_memo[i][j]=true;
        if(s[i]==s[j]&&is_pal(s,i+1,j-1))
        {
            is_pal(s,i+1,j);
            is_pal(s,i,j-1);
            return pal_memo[i][j]=true;
        }
        is_pal(s,i+1,j);
        is_pal(s,i,j-1);
        return pal_memo[i][j]=false;
    }
    int min_part(string &s,int i,int j)
    {
        if(memo[i][j]!=-1)
            return memo[i][j];
        if(i==j)
            return memo[i][j]=0;
        if(pal_memo[i][j])
            return memo[i][j]=0;
        memo[i][j]=INT_MAX;
        for(int k=i;k<j;k++)
            memo[i][j]=min(memo[i][j],1+min_part(s,i,k)+min_part(s,k+1,j));
        return memo[i][j];
        
    }
    int minCut(string s) 
    {
        if(s.empty())
            return 0;
        memo.resize(s.length(),vector<int>(s.length(),-1));
        pal_memo.resize(s.length(),vector<int>(s.length(),-1));
        is_pal(s,0,s.length()-1);
        return min_part(s,0,s.length()-1);
    }
};