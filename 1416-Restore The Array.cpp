static int MOD=1e9+7;
class Solution {
public:
    int k;
    vector<int> memo;
    int dp(string &s,int start)
    {
        if(start==s.length())
            return 1;
        if(memo[start]!=-1)
            return memo[start];
        long temp=0;
        memo[start]=0;
        for(int i=start;i<s.length();i++)
        {
            temp=temp*10+s[i]-'0';
            if(temp>0&&temp<=k)
                memo[start]=(memo[start]+dp(s,i+1))%MOD;
            else
                break;
        }
        return memo[start];
    }
    int numberOfArrays(string s, int k)
    {
        this->k=k;
        memo.resize(s.length(),-1);
        return dp(s,0);
    }
};