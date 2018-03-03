class Solution {
public:
    vector<vector<int>> memo;
    bool isInterleave(string &s1,string &s2,string &s3,int i,int j,int x)
    {
        if(x==0&&i==0&&j==0)
            return true;
        else if(x==0)
            return false;
        else if(memo[i][j]!=-1)
            return memo[i][j];
        return memo[i][j]=(i>0&&s3[x-1]==s1[i-1]&&isInterleave(s1,s2,s3,i-1,j,x-1))||(j>0&&s3[x-1]==s2[j-1]&&isInterleave(s1,s2,s3,i,j-1,x-1));
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s3.length()!=s2.length()+s1.length())
            return false;
        memo.resize(s1.length()+1,vector<int>(s2.length()+1,-1));
        return isInterleave(s1,s2,s3,s1.length(),s2.length(),s3.length());
    }
};