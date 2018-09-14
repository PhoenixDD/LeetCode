class Solution {
public:
    int Max=1,begin=-1;
    vector<vector<int>> memo;
    bool longestPalindrome(string &s,int i,int j)
    {
        if(memo[i][j]!=-1)
            return memo[i][j];
        if(i==j)
            return true;
        if(i==j-1&&s[i]==s[j])
        {
            if(2>Max)
                Max=2,begin=i;
            return true;
        }
        longestPalindrome(s,i+1,j),longestPalindrome(s,i,j-1);
        if(s[i]==s[j]&&longestPalindrome(s,i+1,j-1))
        {
            if(j-i+1>Max)
                Max=j-i+1,begin=i;
            return memo[i][j]=true;
        }
        return memo[i][j]=false;
    }
    string longestPalindrome(string s) 
    {
        if(s.empty())
            return "";
        memo.resize(s.length(),vector<int>(s.length(),-1));
        longestPalindrome(s,0,s.length()-1);
        return Max==1?string(1,s[0]):s.substr(begin,Max);
    }
};