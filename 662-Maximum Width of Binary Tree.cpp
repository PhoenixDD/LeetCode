//reduce the length of entire string by removing continuous duplicates,
//as they will be printed in one print result will be same but time decreases
//we have two options either print the letter (1st option +1)
//or we can get the minimum of all places matching the current letter as same
//letter printed till that point and then check those edits i,k-1 + k+1,j.

class Solution {
public:
    vector<vector<int>> memo;
    int strangePrinter(string &s,int i,int j)
    {
        if(i>j)
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        memo[i][j]=1+strangePrinter(s,i+1,j);
        for(int k=i+1;k<=j;k++)
            if(s[i]==s[k])
                memo[i][j]=min(memo[i][j],strangePrinter(s,i,k-1)+strangePrinter(s,k+1,j));
        return memo[i][j];
    }
    int strangePrinter(string s) 
    {
        int pos=0;
        for(int i=0;i<s.length();i++)
        {
            s[pos++]=s[i];
            while(i<s.length()-1&&s[i]==s[i+1])
                i++;
        }
        s.resize(pos);
        memo.resize(s.length(),vector<int>(s.length(),-1));
        return strangePrinter(s,0,s.length()-1);
    }
};